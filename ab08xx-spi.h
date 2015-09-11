
#ifndef __AB18XX_RTC_H__
#define __AB18XX_RTC_H__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define TIME_DATE 0x00
#define ALARM_DATE 0x08
#define ID0 0x28

#define SPI_READ(offset) (0x7F & offset)
#define SPI_WRITE(offset) (0x80 | offset)

struct ab08xx_t {
        struct spi_device       *spi;
        struct rtc_device       *rtc;
	u8			id_msb;
	u8			id_lsb;
};


static int ab08xx_read_time(struct device *dev, struct rtc_time *dt);

static int ab08xx_set_time(struct device *dev, struct rtc_time *dt);

static int ab08xx_get_alarm(struct device *dev, struct rtc_wkalrm *alm);

static int ab08xx_set_alarm(struct device *dev, struct rtc_wkalrm *alm);

static int ab08xx_alarm_irq_enable(struct device *dev, unsigned int enabled);

static int ab08xx_proc(struct device *dev, struct seq_file *seq);

static int ab08xx_rtc_ioctl(struct device *dev, unsigned int cmd, unsigned long arg);

static void ab08xx_shutdown(void);

static struct ab08xx_t ab08xx_clock;

#endif
