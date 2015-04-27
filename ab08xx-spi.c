/*
 * Driver for the ab08xx series SPI Real Time Clocks
 * Copyright (C) 2015 NigelB
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/syscore_ops.h>
#include <linux/rtc.h>
#include <linux/spi/spi.h>
#include <linux/bcd.h>
#include "ab08xx-spi.h"

static const struct rtc_class_ops ab08xx_rtc_ops = {
        .read_time        = ab08xx_read_time,
        .set_time         = ab08xx_set_time,
        .read_alarm       = ab08xx_get_alarm,
        .set_alarm        = ab08xx_set_alarm,
	.alarm_irq_enable = ab08xx_alarm_irq_enable,	
	.proc             = ab08xx_proc,
//	.ioctl            = ab08xx_rtc_ioctl,
};

static struct syscore_ops ab08xx_syscore_ops = {
	.shutdown = ab08xx_shutdown,
};

static void powergizmo_mark(void)
{
	u8 addr[5];
	int status;
	printk(KERN_EMERG "++++++++++++++++++++MARK...\n");

	addr[0] = SPI_WRITE(0x40);
	addr[1] = 0xde;
	addr[2] = 0xad;
	addr[3] = 0xbe;
	addr[4] = 0xef;

	status = spi_write_then_read(power_gizmo.spi, &addr, sizeof(addr),
                        NULL, 0);
	if(status){}
}

static void powergizmo_read_mark(void)
{
	u8 addr[4];
	int status;
	printk(KERN_INFO "++++++++++++++++++++READ MARK...\n");

	addr[0] = SPI_READ(0x40);

	status = spi_write_then_read(power_gizmo.spi, &addr, 1,
                        &addr, 4);
	printk(KERN_INFO "Read Mark %02x %02x %02x %02x \n", addr[0], addr[1], addr[2], addr[3]);
	
}

/*
static void powergizmo_pm_power_off(void)
{
	printk(KERN_EMERG "++++++++++++++++++++POWERDOWN...\n");
	powergizmo_mark();
	power_gizmo.original_pm_power_off();	

}
*/

static int ab08xx_read_reg(struct ab08xx_t *ab08xx, u8 address, u8 *data)
{
        *data = SPI_READ(address);
        return spi_write_then_read(ab08xx->spi, data, 1, data, 1);
}

static int ab08xx_write_reg(struct ab08xx_t *ab08xx, u8 address, u8 data)
{
        unsigned char buf[2];

        buf[0] = SPI_WRITE(address);
        buf[1] = data;

        return spi_write_then_read(ab08xx->spi, buf, 2, NULL, 0);
}

static void ab08xx_shutdown()
{
	printk(KERN_EMERG "++++++++++++++++++++ABPOWERDOWN...\n");
	printk(KERN_EMERG "PowerGizmo MSB: %i\n", power_gizmo.id_msb);
	//printk(KERN_EMERG "PowerGizmo SPI: %i\n", power_gizmo.spi);
	
	if(SYSTEM_POWER_OFF == SYSTEM_POWER_OFF)
	{
		powergizmo_mark();
	}
}

static int ab08xx_read_time(struct device *dev, struct rtc_time *dt)
{
	struct ab08xx_t         *ab08xx = dev_get_drvdata(dev);
	int 			status;
	u8			addr = SPI_READ(TIME_DATE), count = 1, buf[8];

	memset(&buf, 0, sizeof buf);

	status = spi_write_then_read(ab08xx->spi, &addr, sizeof(addr),
                        buf, sizeof(buf));

	//printk(KERN_INFO "Hour: %i %02x\n", buf[2], buf[2]);
        dt->tm_sec = bcd2bin(0x7F & buf[count++]);
        dt->tm_min = bcd2bin(0x7F & buf[count++]);
        dt->tm_hour = bcd2bin(0x3F & buf[count++]);
        dt->tm_mday = bcd2bin(0x3F & buf[count++]);
        dt->tm_mon = bcd2bin(0x0F & buf[count++]) - 1;
	
	//printk(KERN_INFO "Offset: %i %02x\n", count, count);
	//printk(KERN_INFO "Year: %i %i %02x\n", buf[count], bcd2bin(buf[count]), buf[count]);
        dt->tm_year = bcd2bin(buf[count++]) + 100;
        dt->tm_wday = (0x07 & buf[count++]);
	//powergizmo_mark();
//	powergizmo_read_mark();
	return rtc_valid_tm(dt);
}

static int ab08xx_set_time(struct device *dev, struct rtc_time *dt)
{
	int 			status;
	u8			addr = SPI_READ(TIME_DATE), count, buf[9];
	struct ab08xx_t         *ab08xx = dev_get_drvdata(dev);

	count = 0;

	memset(&buf, 0, sizeof buf);


	status = spi_write_then_read(ab08xx->spi, &addr, sizeof(addr),
                        buf+1, sizeof(buf)-1);

	
	printk(KERN_INFO "%02x %02x %02x %02x %02x %02x %02x %02x %02x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8]);

	buf[count++] = SPI_WRITE(TIME_DATE);
	buf[count++] = 0; // Set Hundredths to 0

	buf[count] = (~0x7F & buf[count++]) | (0x7F & bin2bcd(dt->tm_sec));
	buf[count] = (~0x7F & buf[count++]) | (0x7F & bin2bcd(dt->tm_min));
	buf[count] = (~0x3F & buf[count++]) | (0x3F & bin2bcd(dt->tm_hour));
	buf[count] = (~0x3F & buf[count++]) | (0x3F & bin2bcd(dt->tm_mday));
	buf[count] = ((~0x0F & buf[count++]) | (0x0F & bin2bcd(dt->tm_mon))) + 1;
	buf[count++] =  bin2bcd(dt->tm_year - 100);
	buf[count] = (~0x07 & buf[count++]) | (0x07 & dt->tm_wday);

	printk(KERN_INFO "%02x %02x %02x %02x %02x %02x %02x %02x %02x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8]);

	return spi_write_then_read(ab08xx->spi, buf, sizeof(buf), NULL, 0);
}

static int ab08xx_get_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct ab08xx_t         *ab08xx = dev_get_drvdata(dev);
	int 			status;
	u8			count = 1, buf[8];
	struct rtc_time *dt = &alm->time;

	memset(&buf, 0, sizeof buf);

	buf[0] = SPI_READ(ALARM_DATE);

	status = spi_write_then_read(ab08xx->spi, buf, 1, buf, sizeof(buf));
	if(status < 0)
	{
		return -EIO;
	}

        dt->tm_sec = bcd2bin(0x7F & buf[count++]);
        dt->tm_min = bcd2bin(0x7F & buf[count++]);
        dt->tm_hour = bcd2bin(0x3F & buf[count++]);
        dt->tm_mday = bcd2bin(0x3F & buf[count++]);
        dt->tm_mon = bcd2bin(0x0F & buf[count++]) - 1;
	
        dt->tm_year = bcd2bin(buf[count++]) + 100;
        dt->tm_wday = (0x07 & buf[count++]);
	
	return rtc_valid_tm(dt);


}

static int ab08xx_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	int  status;
	u8   buf[9];
	struct ab08xx_t         *ab08xx = dev_get_drvdata(dev);
	struct rtc_time *dt = &alm->time;

	memset(&buf, 0, sizeof buf);

	printk(KERN_EMERG "SET ALARM %i-%i-%i %i:%i:%i\n", dt->tm_year, dt->tm_mon, dt->tm_mday, dt->tm_hour, dt->tm_min, dt->tm_sec);
	buf[0] = SPI_READ(ALARM_DATE);
	status = spi_write_then_read(ab08xx->spi, buf, 1, buf+1, sizeof(buf)-1);

	buf[0] = SPI_WRITE(ALARM_DATE);
	buf[1] = 0; //Set the Hundredths alarm register to 0
	
	buf[2] = (~0x7F & buf[2]) | (0x7F & bin2bcd(dt->tm_sec));
	buf[3] = (~0x7F & buf[3]) | (0x7F & bin2bcd(dt->tm_min));
	buf[4] = (~0x3F & buf[4]) | (0x3F & bin2bcd(dt->tm_hour));
	buf[5] = (~0x3F & buf[5]) | (0x3F & bin2bcd(dt->tm_mday));
	buf[6] = ((~0x0F & buf[6]) | (0x0F & bin2bcd(dt->tm_mon))) + 1;
	buf[7] =  bin2bcd(dt->tm_year - 100);
	buf[8] = (~0x07 & buf[8]) | (0x07 & dt->tm_wday);
	return spi_write_then_read(ab08xx->spi, buf, sizeof(buf), NULL, 0);
	
}

static int ab08xx_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	return -EINVAL;
}

static int ab08xx_proc(struct device *dev, struct seq_file *seq)
{
	u8   buf[8];
	int addr, status;
	struct ab08xx_t *ab08xx = dev_get_drvdata(dev);

	seq_printf(seq,"\n\nHex Dump:\n\n");

	for(addr = 0; addr < 0x80; addr += 8)
	{
		buf[0] = SPI_READ(addr);
		status = spi_write_then_read(ab08xx->spi, buf, 1, buf, sizeof(buf));
		if(status < 0)
		{
			return status;
		}
		status = seq_printf(seq, "\t0x%02x: %02x %02x %02x %02x %02x %02x %02x %02x\n", addr, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
		if(status < 0)
		{
			return status;
		}
	}

	return status;	
	
}

ssize_t show_ab08xx_clock_id_SERIAL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);
        u8 data[2];
	int val = 0;

        data[0] = SPI_READ(0x2CU);
	data[1] = 0;

        if(spi_write_then_read(ab08xx->spi, data, 1, data, 2) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }

	val = ((0x7F & data[1]) << 8) & data[0];

        return sprintf(buf, "%i", val);

}

#include "ab08xx-spi-sysfs.c"

int ab08xx_register_sysfs(struct ab08xx_t* clock)
{
	return sysfs_create_groups(&clock->rtc->dev.kobj, (const struct attribute_group **)&ab08xx_groups);	
}

void ab08xx_unregister_sysfs(struct ab08xx_t* clock)
{
	sysfs_remove_groups(&clock->rtc->dev.kobj, (const struct attribute_group **)&ab08xx_groups);
}

static int ab08xx_probe(struct spi_device *spi)
{
	struct ab08xx_t		*ab08xx;
	int			status;
	u8 			addr, id[2];
	char			clock_name[20];
	
	printk(KERN_EMERG "++++++++++++++++++++Starting clock...\n");
	memset(&power_gizmo, 0, sizeof(power_gizmo));
	printk(KERN_EMERG "PowerGizmo MSB: %i\n", power_gizmo.id_msb);
	
	ab08xx = devm_kzalloc(&spi->dev, sizeof(*ab08xx), GFP_KERNEL);
	if (!ab08xx)
	{
                return -ENOMEM;
	}

	ab08xx->spi = spi;
	spi_set_drvdata(spi, ab08xx);

	addr = ID0;
	status = spi_write_then_read(spi, &addr, 1, id, sizeof(id));
	if(status < 0)
	{
		dev_dbg(&spi->dev, "can't %s, %d\n", "read", status);
		return status;
	}
	ab08xx->id_msb = id[0];
	ab08xx->id_lsb = id[1];
	
	if((ab08xx->id_msb == 0x18 || ab08xx->id_msb == 0x08) && 
		(ab08xx->id_lsb == 0x04 || ab08xx->id_lsb == 0x14 || 
		ab08xx->id_lsb == 0x05 || ab08xx->id_lsb == 0x15))
	{
		sprintf(clock_name, "AB%02x%02x", id[0], id[1]);
		printk(KERN_EMERG "Found Abracon RTC: AB%02x%02x \n", id[0], id[1]);
		printk(KERN_EMERG "Found Abracon RTC: %s\n", clock_name);
	
	}else{
                return -EINVAL;
	}

	power_gizmo.spi = spi;
       /* register RTC ... from here on, ds1305->ctrl needs locking */
        ab08xx->rtc = devm_rtc_device_register(&spi->dev, clock_name,
                        &ab08xx_rtc_ops, THIS_MODULE);

	//No update interrupt support
	ab08xx->rtc->uie_unsupported = 1;

        if (IS_ERR(ab08xx->rtc)) {
                status = PTR_ERR(ab08xx->rtc);
                dev_dbg(&spi->dev, "register rtc --> %d\n", status);
                return status;
        }
	dev_set_drvdata(&ab08xx->rtc->dev, ab08xx);
	power_gizmo.id_msb = 100;
	register_syscore_ops(&ab08xx_syscore_ops);
	//power_gizmo.original_pm_power_off = pm_power_off;
	//pm_power_off = &powergizmo_pm_power_off;
	printk(KERN_INFO "RTC ID: %i\n", ab08xx->rtc->id);
	printk(KERN_INFO "RTC name: %s\n", ab08xx->rtc->name);

	ab08xx_register_sysfs(ab08xx);
//	device_set_wakeup_capable(&spi->dev, 1);
	return 0;

}

static int ab08xx_remove(struct spi_device *spi)
{
	struct ab08xx_t *ab08xx = spi_get_drvdata(spi);
	unregister_syscore_ops(&ab08xx_syscore_ops);
	ab08xx_unregister_sysfs(ab08xx);
	devm_rtc_device_unregister(&spi->dev, ab08xx->rtc);
	
	printk(KERN_EMERG "++++++++++++++++++++Shutting down clock...\n");
        return 0;
}

static struct spi_driver ab08xx_driver = {
        .driver = {
                .name    = "ab08xx",
                .owner  = THIS_MODULE,
        },
        .probe   = ab08xx_probe,
        .remove = ab08xx_remove,
};

module_spi_driver(ab08xx_driver);

MODULE_DESCRIPTION("ABX8XX SPI RTC driver");
MODULE_AUTHOR("Nigel Bajema <nigel.bajema@gmail.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("spi:ab08xx");
