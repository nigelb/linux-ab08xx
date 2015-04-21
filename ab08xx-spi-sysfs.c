
#define ab08xx_DEVICE_ATTR(_group, _name, _mode, _show, _store)         struct device_attribute dev_attr_##ab08xx_##_group##_##_name = __ATTR(_name, _mode, _show, _store)

#define ab08xx_DEVICE_ATTR_RO(_group, _name, _show) 	struct device_attribute dev_attr_##ab08xx_##_group##_##_name = {			.attr   = { .name = __stringify(_name), .mode = S_IRUGO },			.show   = _show,							};


ssize_t show_ab08xx_status_CB(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_status_CB(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, CB, S_IWUSR | S_IRUGO, show_ab08xx_status_CB, store_ab08xx_status_CB);



ssize_t show_ab08xx_status_BAT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

ssize_t store_ab08xx_status_BAT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, BAT, S_IWUSR | S_IRUGO, show_ab08xx_status_BAT, store_ab08xx_status_BAT);



ssize_t show_ab08xx_status_WDT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

ssize_t store_ab08xx_status_WDT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, WDT, S_IWUSR | S_IRUGO, show_ab08xx_status_WDT, store_ab08xx_status_WDT);



ssize_t show_ab08xx_status_BL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_status_BL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, BL, S_IWUSR | S_IRUGO, show_ab08xx_status_BL, store_ab08xx_status_BL);



ssize_t show_ab08xx_status_TIM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) >> 3);

}

ssize_t store_ab08xx_status_TIM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, TIM, S_IWUSR | S_IRUGO, show_ab08xx_status_TIM, store_ab08xx_status_TIM);



ssize_t show_ab08xx_status_ALM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) >> 2);

}

ssize_t store_ab08xx_status_ALM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, ALM, S_IWUSR | S_IRUGO, show_ab08xx_status_ALM, store_ab08xx_status_ALM);



ssize_t show_ab08xx_status_EX2(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

ssize_t store_ab08xx_status_EX2(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x02;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 1);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, EX2, S_IWUSR | S_IRUGO, show_ab08xx_status_EX2, store_ab08xx_status_EX2);



ssize_t show_ab08xx_status_EX1(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) >> 0);

}

ssize_t store_ab08xx_status_EX1(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x0FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x0FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(status, EX1, S_IWUSR | S_IRUGO, show_ab08xx_status_EX1, store_ab08xx_status_EX1);



ssize_t show_ab08xx_status(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x0F, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_status(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x0FU, usr);	
	
        return count;
}

static DEVICE_ATTR(status, S_IWUSR | S_IRUGO, show_ab08xx_status, store_ab08xx_status);



static const struct attribute *ab08xx_status_attrs[] = {
	&dev_attr_ab08xx_status_CB.attr,
	&dev_attr_ab08xx_status_BAT.attr,
	&dev_attr_ab08xx_status_WDT.attr,
	&dev_attr_ab08xx_status_BL.attr,
	&dev_attr_ab08xx_status_TIM.attr,
	&dev_attr_ab08xx_status_ALM.attr,
	&dev_attr_ab08xx_status_EX2.attr,
	&dev_attr_ab08xx_status_EX1.attr,
	&dev_attr_status.attr,
        NULL
};

static const struct attribute_group ab08xx_status = {
        .attrs =   (struct attribute **)&ab08xx_status_attrs,
        .name = "status",
};



ssize_t show_ab08xx_control1_STOP(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) > 0);

}

ssize_t store_ab08xx_control1_STOP(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, STOP, S_IWUSR | S_IRUGO, show_ab08xx_control1_STOP, store_ab08xx_control1_STOP);



ssize_t show_ab08xx_control1_12_14(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) > 0);

}

ssize_t store_ab08xx_control1_12_14(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, 12_14, S_IWUSR | S_IRUGO, show_ab08xx_control1_12_14, store_ab08xx_control1_12_14);



ssize_t show_ab08xx_control1_OUTB(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) > 0);

}

ssize_t store_ab08xx_control1_OUTB(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, OUTB, S_IWUSR | S_IRUGO, show_ab08xx_control1_OUTB, store_ab08xx_control1_OUTB);



ssize_t show_ab08xx_control1_OUT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) > 0);

}

ssize_t store_ab08xx_control1_OUT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, OUT, S_IWUSR | S_IRUGO, show_ab08xx_control1_OUT, store_ab08xx_control1_OUT);



ssize_t show_ab08xx_control1_RSP(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) > 0);

}

ssize_t store_ab08xx_control1_RSP(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, RSP, S_IWUSR | S_IRUGO, show_ab08xx_control1_RSP, store_ab08xx_control1_RSP);



ssize_t show_ab08xx_control1_ARST(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) > 0);

}

ssize_t store_ab08xx_control1_ARST(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, ARST, S_IWUSR | S_IRUGO, show_ab08xx_control1_ARST, store_ab08xx_control1_ARST);



ssize_t show_ab08xx_control1_WRTC(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) > 0);

}

ssize_t store_ab08xx_control1_WRTC(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x10U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x10U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control1, WRTC, S_IWUSR | S_IRUGO, show_ab08xx_control1_WRTC, store_ab08xx_control1_WRTC);



ssize_t show_ab08xx_control1(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x10, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_control1(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x10U, usr);	
	
        return count;
}

static DEVICE_ATTR(control1, S_IWUSR | S_IRUGO, show_ab08xx_control1, store_ab08xx_control1);



static const struct attribute *ab08xx_control1_attrs[] = {
	&dev_attr_ab08xx_control1_STOP.attr,
	&dev_attr_ab08xx_control1_12_14.attr,
	&dev_attr_ab08xx_control1_OUTB.attr,
	&dev_attr_ab08xx_control1_OUT.attr,
	&dev_attr_ab08xx_control1_RSP.attr,
	&dev_attr_ab08xx_control1_ARST.attr,
	&dev_attr_ab08xx_control1_WRTC.attr,
	&dev_attr_control1.attr,
        NULL
};

static const struct attribute_group ab08xx_control1 = {
        .attrs =   (struct attribute **)&ab08xx_control1_attrs,
        .name = "control1",
};



ssize_t show_ab08xx_control2_OUT1S(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x11U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x03) >> 0);

}

ssize_t store_ab08xx_control2_OUT1S(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x03;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x11U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x11U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control2, OUT1S, S_IWUSR | S_IRUGO, show_ab08xx_control2_OUT1S, store_ab08xx_control2_OUT1S);



ssize_t show_ab08xx_control2_OUT2S(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x11U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x1c) >> 2);

}

ssize_t store_ab08xx_control2_OUT2S(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x1c;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x11U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x11U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(control2, OUT2S, S_IWUSR | S_IRUGO, show_ab08xx_control2_OUT2S, store_ab08xx_control2_OUT2S);



ssize_t show_ab08xx_control2(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x11, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_control2(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x11U, usr);	
	
        return count;
}

static DEVICE_ATTR(control2, S_IWUSR | S_IRUGO, show_ab08xx_control2, store_ab08xx_control2);



static const struct attribute *ab08xx_control2_attrs[] = {
	&dev_attr_ab08xx_control2_OUT1S.attr,
	&dev_attr_ab08xx_control2_OUT2S.attr,
	&dev_attr_control2.attr,
        NULL
};

static const struct attribute_group ab08xx_control2 = {
        .attrs =   (struct attribute **)&ab08xx_control2_attrs,
        .name = "control2",
};



ssize_t show_ab08xx_int_CEB(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_int_CEB(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, CEB, S_IWUSR | S_IRUGO, show_ab08xx_int_CEB, store_ab08xx_int_CEB);



ssize_t show_ab08xx_int_IM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x60) >> 5);

}

ssize_t store_ab08xx_int_IM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x60;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, IM, S_IWUSR | S_IRUGO, show_ab08xx_int_IM, store_ab08xx_int_IM);



ssize_t show_ab08xx_int_BLIE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_int_BLIE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, BLIE, S_IWUSR | S_IRUGO, show_ab08xx_int_BLIE, store_ab08xx_int_BLIE);



ssize_t show_ab08xx_int_TIE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) >> 3);

}

ssize_t store_ab08xx_int_TIE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, TIE, S_IWUSR | S_IRUGO, show_ab08xx_int_TIE, store_ab08xx_int_TIE);



ssize_t show_ab08xx_int_AIE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) >> 2);

}

ssize_t store_ab08xx_int_AIE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, AIE, S_IWUSR | S_IRUGO, show_ab08xx_int_AIE, store_ab08xx_int_AIE);



ssize_t show_ab08xx_int_EX2E(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

ssize_t store_ab08xx_int_EX2E(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x02;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 1);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, EX2E, S_IWUSR | S_IRUGO, show_ab08xx_int_EX2E, store_ab08xx_int_EX2E);



ssize_t show_ab08xx_int_EX1E(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) >> 0);

}

ssize_t store_ab08xx_int_EX1E(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x12U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x12U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(int, EX1E, S_IWUSR | S_IRUGO, show_ab08xx_int_EX1E, store_ab08xx_int_EX1E);



ssize_t show_ab08xx_int(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x12, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_int(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x12U, usr);	
	
        return count;
}

static DEVICE_ATTR(int, S_IWUSR | S_IRUGO, show_ab08xx_int, store_ab08xx_int);



static const struct attribute *ab08xx_int_attrs[] = {
	&dev_attr_ab08xx_int_CEB.attr,
	&dev_attr_ab08xx_int_IM.attr,
	&dev_attr_ab08xx_int_BLIE.attr,
	&dev_attr_ab08xx_int_TIE.attr,
	&dev_attr_ab08xx_int_AIE.attr,
	&dev_attr_ab08xx_int_EX2E.attr,
	&dev_attr_ab08xx_int_EX1E.attr,
	&dev_attr_int.attr,
        NULL
};

static const struct attribute_group ab08xx_int = {
        .attrs =   (struct attribute **)&ab08xx_int_attrs,
        .name = "int",
};



ssize_t show_ab08xx_sqw_SQWE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x13U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x60) >> 5);

}

ssize_t store_ab08xx_sqw_SQWE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x60;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x13U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x13U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sqw, SQWE, S_IWUSR | S_IRUGO, show_ab08xx_sqw_SQWE, store_ab08xx_sqw_SQWE);



ssize_t show_ab08xx_sqw_SQFS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x13U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x1F) >> 0);

}

ssize_t store_ab08xx_sqw_SQFS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x1F;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x13U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x13U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sqw, SQFS, S_IWUSR | S_IRUGO, show_ab08xx_sqw_SQFS, store_ab08xx_sqw_SQFS);



ssize_t show_ab08xx_sqw(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x13, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_sqw(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x13U, usr);	
	
        return count;
}

static DEVICE_ATTR(sqw, S_IWUSR | S_IRUGO, show_ab08xx_sqw, store_ab08xx_sqw);



static const struct attribute *ab08xx_sqw_attrs[] = {
	&dev_attr_ab08xx_sqw_SQWE.attr,
	&dev_attr_ab08xx_sqw_SQFS.attr,
	&dev_attr_sqw.attr,
        NULL
};

static const struct attribute_group ab08xx_sqw = {
        .attrs =   (struct attribute **)&ab08xx_sqw_attrs,
        .name = "sqw",
};



ssize_t show_ab08xx_calibration_CMDX(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x14U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_calibration_CMDX(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x14U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x14U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(calibration, CMDX, S_IWUSR | S_IRUGO, show_ab08xx_calibration_CMDX, store_ab08xx_calibration_CMDX);



ssize_t show_ab08xx_calibration_OFFSETX(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x14U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x7F) >> 0);

}

ssize_t store_ab08xx_calibration_OFFSETX(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x7F;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x14U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x14U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(calibration, OFFSETX, S_IWUSR | S_IRUGO, show_ab08xx_calibration_OFFSETX, store_ab08xx_calibration_OFFSETX);



ssize_t show_ab08xx_calibration_CMDR(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x15U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xC0) >> 6);

}

ssize_t store_ab08xx_calibration_CMDR(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xC0;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x15U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x15U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(calibration, CMDR, S_IWUSR | S_IRUGO, show_ab08xx_calibration_CMDR, store_ab08xx_calibration_CMDR);



ssize_t show_ab08xx_calibration_OFFSETRU(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x15U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x3F) >> 0);

}

ssize_t store_ab08xx_calibration_OFFSETRU(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x3F;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x15U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x15U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(calibration, OFFSETRU, S_IWUSR | S_IRUGO, show_ab08xx_calibration_OFFSETRU, store_ab08xx_calibration_OFFSETRU);



ssize_t show_ab08xx_calibration_OFFSETRL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x16U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xFF) >> 0);

}

ssize_t store_ab08xx_calibration_OFFSETRL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xFF;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x16U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x16U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(calibration, OFFSETRL, S_IWUSR | S_IRUGO, show_ab08xx_calibration_OFFSETRL, store_ab08xx_calibration_OFFSETRL);



ssize_t show_ab08xx_calibration_xt(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x16, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_calibration_xt(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x16U, usr);	
	
        return count;
}

static DEVICE_ATTR(calibration_xt, S_IWUSR | S_IRUGO, show_ab08xx_calibration_xt, store_ab08xx_calibration_xt);



ssize_t show_ab08xx_calibration_rc_upper(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x15, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_calibration_rc_upper(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x15U, usr);	
	
        return count;
}

static DEVICE_ATTR(calibration_rc_upper, S_IWUSR | S_IRUGO, show_ab08xx_calibration_rc_upper, store_ab08xx_calibration_rc_upper);



ssize_t show_ab08xx_calibration_rc_lower(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x16, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_calibration_rc_lower(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x16U, usr);	
	
        return count;
}

static DEVICE_ATTR(calibration_rc_lower, S_IWUSR | S_IRUGO, show_ab08xx_calibration_rc_lower, store_ab08xx_calibration_rc_lower);



static const struct attribute *ab08xx_calibration_attrs[] = {
	&dev_attr_ab08xx_calibration_CMDX.attr,
	&dev_attr_ab08xx_calibration_OFFSETX.attr,
	&dev_attr_ab08xx_calibration_CMDR.attr,
	&dev_attr_ab08xx_calibration_OFFSETRU.attr,
	&dev_attr_ab08xx_calibration_OFFSETRL.attr,
	&dev_attr_calibration_xt.attr,
	&dev_attr_calibration_rc_upper.attr,
	&dev_attr_calibration_rc_lower.attr,
        NULL
};

static const struct attribute_group ab08xx_calibration = {
        .attrs =   (struct attribute **)&ab08xx_calibration_attrs,
        .name = "calibration",
};



ssize_t show_ab08xx_sleep_SLP(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_sleep_SLP(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, SLP, S_IWUSR | S_IRUGO, show_ab08xx_sleep_SLP, store_ab08xx_sleep_SLP);



ssize_t show_ab08xx_sleep_SLRES(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

ssize_t store_ab08xx_sleep_SLRES(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, SLRES, S_IWUSR | S_IRUGO, show_ab08xx_sleep_SLRES, store_ab08xx_sleep_SLRES);



ssize_t show_ab08xx_sleep_EX2P(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

ssize_t store_ab08xx_sleep_EX2P(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, EX2P, S_IWUSR | S_IRUGO, show_ab08xx_sleep_EX2P, store_ab08xx_sleep_EX2P);



ssize_t show_ab08xx_sleep_EX1P(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_sleep_EX1P(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, EX1P, S_IWUSR | S_IRUGO, show_ab08xx_sleep_EX1P, store_ab08xx_sleep_EX1P);



ssize_t show_ab08xx_sleep_SLST(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) >> 3);

}

ssize_t store_ab08xx_sleep_SLST(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, SLST, S_IWUSR | S_IRUGO, show_ab08xx_sleep_SLST, store_ab08xx_sleep_SLST);



ssize_t show_ab08xx_sleep_SLTO(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x07) >> 0);

}

ssize_t store_ab08xx_sleep_SLTO(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x07;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x17U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x17U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(sleep, SLTO, S_IWUSR | S_IRUGO, show_ab08xx_sleep_SLTO, store_ab08xx_sleep_SLTO);



ssize_t show_ab08xx_sleep(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x17, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_sleep(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x17U, usr);	
	
        return count;
}

static DEVICE_ATTR(sleep, S_IWUSR | S_IRUGO, show_ab08xx_sleep, store_ab08xx_sleep);



static const struct attribute *ab08xx_sleep_attrs[] = {
	&dev_attr_ab08xx_sleep_SLP.attr,
	&dev_attr_ab08xx_sleep_SLRES.attr,
	&dev_attr_ab08xx_sleep_EX2P.attr,
	&dev_attr_ab08xx_sleep_EX1P.attr,
	&dev_attr_ab08xx_sleep_SLST.attr,
	&dev_attr_ab08xx_sleep_SLTO.attr,
	&dev_attr_sleep.attr,
        NULL
};

static const struct attribute_group ab08xx_sleep = {
        .attrs =   (struct attribute **)&ab08xx_sleep_attrs,
        .name = "sleep",
};



ssize_t show_ab08xx_timer_TE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_timer_TE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x18U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, TE, S_IWUSR | S_IRUGO, show_ab08xx_timer_TE, store_ab08xx_timer_TE);



ssize_t show_ab08xx_timer_TM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

ssize_t store_ab08xx_timer_TM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x18U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, TM, S_IWUSR | S_IRUGO, show_ab08xx_timer_TM, store_ab08xx_timer_TM);



ssize_t show_ab08xx_timer_TRPT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

ssize_t store_ab08xx_timer_TRPT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x18U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, TRPT, S_IWUSR | S_IRUGO, show_ab08xx_timer_TRPT, store_ab08xx_timer_TRPT);



ssize_t show_ab08xx_timer_RPT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x1C) >> 2);

}

ssize_t store_ab08xx_timer_RPT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x1C;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x18U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, RPT, S_IWUSR | S_IRUGO, show_ab08xx_timer_RPT, store_ab08xx_timer_RPT);



ssize_t show_ab08xx_timer_TFS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x03) >> 0);

}

ssize_t store_ab08xx_timer_TFS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x03;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x18U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x18U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, TFS, S_IWUSR | S_IRUGO, show_ab08xx_timer_TFS, store_ab08xx_timer_TFS);



ssize_t show_ab08xx_timer_countdown(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x19U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xFF) >> 0);

}

ssize_t store_ab08xx_timer_countdown(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xFF;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x19U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x19U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, countdown, S_IWUSR | S_IRUGO, show_ab08xx_timer_countdown, store_ab08xx_timer_countdown);



ssize_t show_ab08xx_timer_initial_value(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1AU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xFF) >> 0);

}

ssize_t store_ab08xx_timer_initial_value(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xFF;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1AU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x1AU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, initial_value, S_IWUSR | S_IRUGO, show_ab08xx_timer_initial_value, store_ab08xx_timer_initial_value);



ssize_t show_ab08xx_timer_WDS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_timer_WDS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x1BU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, WDS, S_IWUSR | S_IRUGO, show_ab08xx_timer_WDS, store_ab08xx_timer_WDS);



ssize_t show_ab08xx_timer_BMB(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x7C) >> 2);

}

ssize_t store_ab08xx_timer_BMB(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x7C;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x1BU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, BMB, S_IWUSR | S_IRUGO, show_ab08xx_timer_BMB, store_ab08xx_timer_BMB);



ssize_t show_ab08xx_timer_WRB(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x03) >> 0);

}

ssize_t store_ab08xx_timer_WRB(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x03;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1BU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x1BU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(timer, WRB, S_IWUSR | S_IRUGO, show_ab08xx_timer_WRB, store_ab08xx_timer_WRB);



ssize_t show_ab08xx_timer(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1B, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_timer(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x1BU, usr);	
	
        return count;
}

static DEVICE_ATTR(timer, S_IWUSR | S_IRUGO, show_ab08xx_timer, store_ab08xx_timer);



ssize_t show_ab08xx_watchdog_timer(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1B, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_watchdog_timer(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x1BU, usr);	
	
        return count;
}

static DEVICE_ATTR(watchdog_timer, S_IWUSR | S_IRUGO, show_ab08xx_watchdog_timer, store_ab08xx_watchdog_timer);



static const struct attribute *ab08xx_timer_attrs[] = {
	&dev_attr_ab08xx_timer_TE.attr,
	&dev_attr_ab08xx_timer_TM.attr,
	&dev_attr_ab08xx_timer_TRPT.attr,
	&dev_attr_ab08xx_timer_RPT.attr,
	&dev_attr_ab08xx_timer_TFS.attr,
	&dev_attr_ab08xx_timer_countdown.attr,
	&dev_attr_ab08xx_timer_initial_value.attr,
	&dev_attr_ab08xx_timer_WDS.attr,
	&dev_attr_ab08xx_timer_BMB.attr,
	&dev_attr_ab08xx_timer_WRB.attr,
	&dev_attr_timer.attr,
	&dev_attr_watchdog_timer.attr,
        NULL
};

static const struct attribute_group ab08xx_timer = {
        .attrs =   (struct attribute **)&ab08xx_timer_attrs,
        .name = "timer",
};



ssize_t show_ab08xx_oscillator_OSEL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_oscillator_OSEL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, OSEL, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_OSEL, store_ab08xx_oscillator_OSEL);



ssize_t show_ab08xx_oscillator_ACAL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x60) >> 5);

}

ssize_t store_ab08xx_oscillator_ACAL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x60;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, ACAL, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_ACAL, store_ab08xx_oscillator_ACAL);



ssize_t show_ab08xx_oscillator_AOS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_oscillator_AOS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, AOS, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_AOS, store_ab08xx_oscillator_AOS);



ssize_t show_ab08xx_oscillator_FOS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) >> 3);

}

ssize_t store_ab08xx_oscillator_FOS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, FOS, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_FOS, store_ab08xx_oscillator_FOS);



ssize_t show_ab08xx_oscillator_PWGT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) >> 2);

}

ssize_t store_ab08xx_oscillator_PWGT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, PWGT, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_PWGT, store_ab08xx_oscillator_PWGT);



ssize_t show_ab08xx_oscillator_OFIE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

ssize_t store_ab08xx_oscillator_OFIE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x02;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 1);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, OFIE, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_OFIE, store_ab08xx_oscillator_OFIE);



ssize_t show_ab08xx_oscillator_ACIE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) >> 0);

}

ssize_t store_ab08xx_oscillator_ACIE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1CU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x1CU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, ACIE, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_ACIE, store_ab08xx_oscillator_ACIE);



ssize_t show_ab08xx_oscillator_XTCAL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xC0) >> 6);

}

ssize_t store_ab08xx_oscillator_XTCAL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xC0;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x1DU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, XTCAL, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_XTCAL, store_ab08xx_oscillator_XTCAL);



ssize_t show_ab08xx_oscillator_LKO2(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

ssize_t store_ab08xx_oscillator_LKO2(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x1DU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, LKO2, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_LKO2, store_ab08xx_oscillator_LKO2);



ssize_t show_ab08xx_oscillator_OMODE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_oscillator_OMODE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x1DU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, OMODE, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_OMODE, store_ab08xx_oscillator_OMODE);



ssize_t show_ab08xx_oscillator_OF(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

ssize_t store_ab08xx_oscillator_OF(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x02;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 1);
	ab08xx_write_reg(ab08xx, 0x1DU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, OF, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_OF, store_ab08xx_oscillator_OF);



ssize_t show_ab08xx_oscillator_ACF(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) >> 0);

}

ssize_t store_ab08xx_oscillator_ACF(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x1DU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x1DU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(oscillator, ACF, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_ACF, store_ab08xx_oscillator_ACF);



ssize_t show_ab08xx_oscillator_cont(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1D, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_oscillator_cont(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x1DU, usr);	
	
        return count;
}

static DEVICE_ATTR(oscillator_cont, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_cont, store_ab08xx_oscillator_cont);



ssize_t show_ab08xx_oscillator_status(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1D, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_oscillator_status(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x1DU, usr);	
	
        return count;
}

static DEVICE_ATTR(oscillator_status, S_IWUSR | S_IRUGO, show_ab08xx_oscillator_status, store_ab08xx_oscillator_status);



static const struct attribute *ab08xx_oscillator_attrs[] = {
	&dev_attr_ab08xx_oscillator_OSEL.attr,
	&dev_attr_ab08xx_oscillator_ACAL.attr,
	&dev_attr_ab08xx_oscillator_AOS.attr,
	&dev_attr_ab08xx_oscillator_FOS.attr,
	&dev_attr_ab08xx_oscillator_PWGT.attr,
	&dev_attr_ab08xx_oscillator_OFIE.attr,
	&dev_attr_ab08xx_oscillator_ACIE.attr,
	&dev_attr_ab08xx_oscillator_XTCAL.attr,
	&dev_attr_ab08xx_oscillator_LKO2.attr,
	&dev_attr_ab08xx_oscillator_OMODE.attr,
	&dev_attr_ab08xx_oscillator_OF.attr,
	&dev_attr_ab08xx_oscillator_ACF.attr,
	&dev_attr_oscillator_cont.attr,
	&dev_attr_oscillator_status.attr,
        NULL
};

static const struct attribute_group ab08xx_oscillator = {
        .attrs =   (struct attribute **)&ab08xx_oscillator_attrs,
        .name = "oscillator",
};



ssize_t show_ab08xx_configuration_key(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x1D, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_configuration_key(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x1DU, usr);	
	
        return count;
}

static DEVICE_ATTR(configuration_key, S_IWUSR | S_IRUGO, show_ab08xx_configuration_key, store_ab08xx_configuration_key);



static const struct attribute *ab08xx_configuration_key_attrs[] = {
	&dev_attr_configuration_key.attr,
        NULL
};

static const struct attribute_group ab08xx_configuration_key = {
        .attrs =   (struct attribute **)&ab08xx_configuration_key_attrs,
        .name = "configuration_key",
};



ssize_t show_ab08xx_trickle_TCS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xF0) >> 4);

}

ssize_t store_ab08xx_trickle_TCS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0xF0;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x20U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(trickle, TCS, S_IWUSR | S_IRUGO, show_ab08xx_trickle_TCS, store_ab08xx_trickle_TCS);



ssize_t show_ab08xx_trickle_DIODE(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x0C) >> 2);

}

ssize_t store_ab08xx_trickle_DIODE(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x0C;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x20U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(trickle, DIODE, S_IWUSR | S_IRUGO, show_ab08xx_trickle_DIODE, store_ab08xx_trickle_DIODE);



ssize_t show_ab08xx_trickle_ROUT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x03) >> 0);

}

ssize_t store_ab08xx_trickle_ROUT(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x03;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x20U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x20U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(trickle, ROUT, S_IWUSR | S_IRUGO, show_ab08xx_trickle_ROUT, store_ab08xx_trickle_ROUT);



ssize_t show_ab08xx_trickle(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x20, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_trickle(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x20U, usr);	
	
        return count;
}

static DEVICE_ATTR(trickle, S_IWUSR | S_IRUGO, show_ab08xx_trickle, store_ab08xx_trickle);



static const struct attribute *ab08xx_trickle_attrs[] = {
	&dev_attr_ab08xx_trickle_TCS.attr,
	&dev_attr_ab08xx_trickle_DIODE.attr,
	&dev_attr_ab08xx_trickle_ROUT.attr,
	&dev_attr_trickle.attr,
        NULL
};

static const struct attribute_group ab08xx_trickle = {
        .attrs =   (struct attribute **)&ab08xx_trickle_attrs,
        .name = "trickle",
};



ssize_t show_ab08xx_bref_control_BREF(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x21U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x0F) >> 0);

}

ssize_t store_ab08xx_bref_control_BREF(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x0F;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x21U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x21U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(bref_control, BREF, S_IWUSR | S_IRUGO, show_ab08xx_bref_control_BREF, store_ab08xx_bref_control_BREF);



ssize_t show_ab08xx_bref_control(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x21, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_bref_control(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x21U, usr);	
	
        return count;
}

static DEVICE_ATTR(bref_control, S_IWUSR | S_IRUGO, show_ab08xx_bref_control, store_ab08xx_bref_control);



static const struct attribute *ab08xx_bref_control_attrs[] = {
	&dev_attr_ab08xx_bref_control_BREF.attr,
	&dev_attr_bref_control.attr,
        NULL
};

static const struct attribute_group ab08xx_bref_control = {
        .attrs =   (struct attribute **)&ab08xx_bref_control_attrs,
        .name = "bref_control",
};



ssize_t show_ab08xx_afctrl(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x21, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_afctrl(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x21U, usr);	
	
        return count;
}

static DEVICE_ATTR(afctrl, S_IWUSR | S_IRUGO, show_ab08xx_afctrl, store_ab08xx_afctrl);



static const struct attribute *ab08xx_afctrl_attrs[] = {
	&dev_attr_afctrl.attr,
        NULL
};

static const struct attribute_group ab08xx_afctrl = {
        .attrs =   (struct attribute **)&ab08xx_afctrl_attrs,
        .name = "afctrl",
};



ssize_t show_ab08xx_batmode_io_IOBM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x27U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_batmode_io_IOBM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x27U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x27U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(batmode_io, IOBM, S_IWUSR | S_IRUGO, show_ab08xx_batmode_io_IOBM, store_ab08xx_batmode_io_IOBM);



ssize_t show_ab08xx_batmode_io(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x27, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_batmode_io(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x27U, usr);	
	
        return count;
}

static DEVICE_ATTR(batmode_io, S_IWUSR | S_IRUGO, show_ab08xx_batmode_io, store_ab08xx_batmode_io);



static const struct attribute *ab08xx_batmode_io_attrs[] = {
	&dev_attr_ab08xx_batmode_io_IOBM.attr,
	&dev_attr_batmode_io.attr,
        NULL
};

static const struct attribute_group ab08xx_batmode_io = {
        .attrs =   (struct attribute **)&ab08xx_batmode_io_attrs,
        .name = "batmode_io",
};



ssize_t show_ab08xx_analog_status_BBOD(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

static ab08xx_DEVICE_ATTR_RO(analog_status, BBOD, show_ab08xx_analog_status_BBOD);



ssize_t show_ab08xx_analog_status_BMIN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

static ab08xx_DEVICE_ATTR_RO(analog_status, BMIN, show_ab08xx_analog_status_BMIN);



ssize_t show_ab08xx_analog_status_VINIT(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

static ab08xx_DEVICE_ATTR_RO(analog_status, VINIT, show_ab08xx_analog_status_VINIT);



ssize_t show_ab08xx_analog_status(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2F, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_analog_status(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x2FU, usr);	
	
        return count;
}

static DEVICE_ATTR(analog_status, S_IWUSR | S_IRUGO, show_ab08xx_analog_status, store_ab08xx_analog_status);



static const struct attribute *ab08xx_analog_status_attrs[] = {
	&dev_attr_ab08xx_analog_status_BBOD.attr,
	&dev_attr_ab08xx_analog_status_BMIN.attr,
	&dev_attr_ab08xx_analog_status_VINIT.attr,
	&dev_attr_analog_status.attr,
        NULL
};

static const struct attribute_group ab08xx_analog_status = {
        .attrs =   (struct attribute **)&ab08xx_analog_status_attrs,
        .name = "analog_status",
};



ssize_t show_ab08xx_output_control_WDBM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_output_control_WDBM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, WDBM, S_IWUSR | S_IRUGO, show_ab08xx_output_control_WDBM, store_ab08xx_output_control_WDBM);



ssize_t show_ab08xx_output_control_EXBM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

ssize_t store_ab08xx_output_control_EXBM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, EXBM, S_IWUSR | S_IRUGO, show_ab08xx_output_control_EXBM, store_ab08xx_output_control_EXBM);



ssize_t show_ab08xx_output_control_WDDS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

ssize_t store_ab08xx_output_control_WDDS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x20;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 5);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, WDDS, S_IWUSR | S_IRUGO, show_ab08xx_output_control_WDDS, store_ab08xx_output_control_WDDS);



ssize_t show_ab08xx_output_control_EXDS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

ssize_t store_ab08xx_output_control_EXDS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x10;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 4);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, EXDS, S_IWUSR | S_IRUGO, show_ab08xx_output_control_EXDS, store_ab08xx_output_control_EXDS);



ssize_t show_ab08xx_output_control_RSEN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x08) >> 3);

}

ssize_t store_ab08xx_output_control_RSEN(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x08;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 3);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, RSEN, S_IWUSR | S_IRUGO, show_ab08xx_output_control_RSEN, store_ab08xx_output_control_RSEN);



ssize_t show_ab08xx_output_control_O4EN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) >> 2);

}

ssize_t store_ab08xx_output_control_O4EN(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, O4EN, S_IWUSR | S_IRUGO, show_ab08xx_output_control_O4EN, store_ab08xx_output_control_O4EN);



ssize_t show_ab08xx_output_control_O3EN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x02) >> 1);

}

ssize_t store_ab08xx_output_control_O3EN(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x02;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 1);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, O3EN, S_IWUSR | S_IRUGO, show_ab08xx_output_control_O3EN, store_ab08xx_output_control_O3EN);



ssize_t show_ab08xx_output_control_O1EN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x01) >> 0);

}

ssize_t store_ab08xx_output_control_O1EN(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x01;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x30U, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x30U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(output_control, O1EN, S_IWUSR | S_IRUGO, show_ab08xx_output_control_O1EN, store_ab08xx_output_control_O1EN);



ssize_t show_ab08xx_output_control(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x30, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_output_control(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x30U, usr);	
	
        return count;
}

static DEVICE_ATTR(output_control, S_IWUSR | S_IRUGO, show_ab08xx_output_control, store_ab08xx_output_control);



static const struct attribute *ab08xx_output_control_attrs[] = {
	&dev_attr_ab08xx_output_control_WDBM.attr,
	&dev_attr_ab08xx_output_control_EXBM.attr,
	&dev_attr_ab08xx_output_control_WDDS.attr,
	&dev_attr_ab08xx_output_control_EXDS.attr,
	&dev_attr_ab08xx_output_control_RSEN.attr,
	&dev_attr_ab08xx_output_control_O4EN.attr,
	&dev_attr_ab08xx_output_control_O3EN.attr,
	&dev_attr_ab08xx_output_control_O1EN.attr,
	&dev_attr_output_control.attr,
        NULL
};

static const struct attribute_group ab08xx_output_control = {
        .attrs =   (struct attribute **)&ab08xx_output_control_attrs,
        .name = "output_control",
};



ssize_t show_ab08xx_clock_id_PN3(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x28U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xF0) >> 4);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, PN3, show_ab08xx_clock_id_PN3);



ssize_t show_ab08xx_clock_id_PN2(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x28U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x0F) >> 0);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, PN2, show_ab08xx_clock_id_PN2);



ssize_t show_ab08xx_clock_id_PN1(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x29U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xF0) >> 4);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, PN1, show_ab08xx_clock_id_PN1);



ssize_t show_ab08xx_clock_id_PN0(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x29U, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x0F) >> 0);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, PN0, show_ab08xx_clock_id_PN0);



ssize_t show_ab08xx_clock_id_REV_MAJOR(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2AU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0xF0) >> 4);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, REV_MAJOR, show_ab08xx_clock_id_REV_MAJOR);



ssize_t show_ab08xx_clock_id_REV_MINOR(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x2AU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x0F) >> 0);

}

static ab08xx_DEVICE_ATTR_RO(clock_id, REV_MINOR, show_ab08xx_clock_id_REV_MINOR);




static ab08xx_DEVICE_ATTR_RO(clock_id, SERIAL, show_ab08xx_clock_id_SERIAL);



ssize_t show_ab08xx_clock_id(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x00, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_clock_id(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x00U, usr);	
	
        return count;
}

static DEVICE_ATTR(clock_id, S_IWUSR | S_IRUGO, show_ab08xx_clock_id, store_ab08xx_clock_id);



static const struct attribute *ab08xx_clock_id_attrs[] = {
	&dev_attr_ab08xx_clock_id_PN3.attr,
	&dev_attr_ab08xx_clock_id_PN2.attr,
	&dev_attr_ab08xx_clock_id_PN1.attr,
	&dev_attr_ab08xx_clock_id_PN0.attr,
	&dev_attr_ab08xx_clock_id_REV_MAJOR.attr,
	&dev_attr_ab08xx_clock_id_REV_MINOR.attr,
	&dev_attr_ab08xx_clock_id_SERIAL.attr,
	&dev_attr_clock_id.attr,
        NULL
};

static const struct attribute_group ab08xx_clock_id = {
        .attrs =   (struct attribute **)&ab08xx_clock_id_attrs,
        .name = "clock_id",
};



ssize_t show_ab08xx_extention_ram_O4BM(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x80) >> 7);

}

ssize_t store_ab08xx_extention_ram_O4BM(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x80;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 7);
	ab08xx_write_reg(ab08xx, 0x3FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(extention_ram, O4BM, S_IWUSR | S_IRUGO, show_ab08xx_extention_ram_O4BM, store_ab08xx_extention_ram_O4BM);



ssize_t show_ab08xx_extention_ram_BPOL(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x40) >> 6);

}

ssize_t store_ab08xx_extention_ram_BPOL(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x40;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 6);
	ab08xx_write_reg(ab08xx, 0x3FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(extention_ram, BPOL, S_IWUSR | S_IRUGO, show_ab08xx_extention_ram_BPOL, store_ab08xx_extention_ram_BPOL);



ssize_t show_ab08xx_extention_ram_WDIN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x20) >> 5);

}

static ab08xx_DEVICE_ATTR_RO(extention_ram, WDIN, show_ab08xx_extention_ram_WDIN);



ssize_t show_ab08xx_extention_ram_EXIN(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x10) >> 4);

}

static ab08xx_DEVICE_ATTR_RO(extention_ram, EXIN, show_ab08xx_extention_ram_EXIN);



ssize_t show_ab08xx_extention_ram_XADA(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x04) >> 2);

}

ssize_t store_ab08xx_extention_ram_XADA(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x04;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 2);
	ab08xx_write_reg(ab08xx, 0x3FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(extention_ram, XADA, S_IWUSR | S_IRUGO, show_ab08xx_extention_ram_XADA, store_ab08xx_extention_ram_XADA);



ssize_t show_ab08xx_extention_ram_XADS(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", (data[0] & 0x03) >> 0);

}

ssize_t store_ab08xx_extention_ram_XADS(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = 0x03;
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}


        if(ab08xx_read_reg(ab08xx, 0x3FU, data) < 0)
        {
		printk(KERN_INFO "Error occoured when reading clock.\n");		
        }

	data[0] = (data[0] & (~mask)) | (usr << 0);
	ab08xx_write_reg(ab08xx, 0x3FU, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\n", data[0]);		
	
        return count;
}

static ab08xx_DEVICE_ATTR(extention_ram, XADS, S_IWUSR | S_IRUGO, show_ab08xx_extention_ram_XADS, store_ab08xx_extention_ram_XADS);



ssize_t show_ab08xx_extention_ram(struct device *dev, struct device_attribute *attr, char *buf)
{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, 0x3F, data) < 0)
        {
                return sprintf(buf, "Error occoured when reading clock.");
        }
        return sprintf(buf, "%i", data[0]);

}

ssize_t store_ab08xx_extention_ram(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        } else {
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }

        if (usr < 0 || usr > 0xffff)
	{
                return -EINVAL;
	}

	printk(KERN_INFO "Write Reg: %i\n", usr);		
	ab08xx_write_reg(ab08xx, 0x3FU, usr);	
	
        return count;
}

static DEVICE_ATTR(extention_ram, S_IWUSR | S_IRUGO, show_ab08xx_extention_ram, store_ab08xx_extention_ram);



static const struct attribute *ab08xx_extention_ram_attrs[] = {
	&dev_attr_ab08xx_extention_ram_O4BM.attr,
	&dev_attr_ab08xx_extention_ram_BPOL.attr,
	&dev_attr_ab08xx_extention_ram_WDIN.attr,
	&dev_attr_ab08xx_extention_ram_EXIN.attr,
	&dev_attr_ab08xx_extention_ram_XADA.attr,
	&dev_attr_ab08xx_extention_ram_XADS.attr,
	&dev_attr_extention_ram.attr,
        NULL
};

static const struct attribute_group ab08xx_extention_ram = {
        .attrs =   (struct attribute **)&ab08xx_extention_ram_attrs,
        .name = "extention_ram",
};



static const struct attribute_group *ab08xx_groups[] = {
	&ab08xx_status,
	&ab08xx_control1,
	&ab08xx_control2,
	&ab08xx_int,
	&ab08xx_sqw,
	&ab08xx_calibration,
	&ab08xx_sleep,
	&ab08xx_timer,
	&ab08xx_oscillator,
	&ab08xx_configuration_key,
	&ab08xx_trickle,
	&ab08xx_bref_control,
	&ab08xx_afctrl,
	&ab08xx_batmode_io,
	&ab08xx_analog_status,
	&ab08xx_output_control,
	&ab08xx_clock_id,
	&ab08xx_extention_ram,
        NULL
};



