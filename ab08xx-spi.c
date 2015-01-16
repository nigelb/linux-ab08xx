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
#include <linux/rtc.h>
#include <linux/spi/spi.h>
#include <linux/bcd.h>


static const struct rtc_class_ops ab08xx_rtc_ops = {
        .read_time      = ab08xx_read_time,
        .set_time       = ab08xx_set_time,
};

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
