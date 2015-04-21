#!/usr/bin/env python

import ctypes
libc = ctypes.cdll.LoadLibrary('libc.so.6')


a="adress"
_group_name="group_name"
name="name"
register_name="reg_name"
f="flags"
m="mask"
p="post"
reg="register"
read_only="R"
read_write="RW"
custom_read_only="custom_RO"
mode="mode"

default_test = "({value} & {mask}) > 0"
shift_test = "({value} & {mask}) >> {shift}"

ap_map=[
	{_group_name:"status", a:"0x0F", f:
		[
#			{n:"CB",  a:"0x0F", m:"0x80", p:default_test},
			{name:"CB",  m:"0x80", p:shift_test},
			{name:"BAT", m:"0x40", p:shift_test},
			{name:"WDT", m:"0x20", p:shift_test},
			{name:"BL",  m:"0x10", p:shift_test},
			{name:"TIM", m:"0x08", p:shift_test},
			{name:"ALM", m:"0x04", p:shift_test},
			{name:"EX2", m:"0x02", p:shift_test},
			{name:"EX1", m:"0x01", p:shift_test},
		]
	},
	{_group_name:"control1", a: "0x10", f:
		[
			{name:"STOP",  m:"0x80", p:default_test},
			{name:"12_14", m:"0x40", p:default_test},
			{name:"OUTB",  m:"0x20", p:default_test},
			{name:"OUT",   m:"0x10", p:default_test},
			{name:"RSP",   m:"0x08", p:default_test},
			{name:"ARST",  m:"0x04", p:default_test},
			{name:"WRTC",  m:"0x01", p:default_test},
		]
	},
	{_group_name:"control2", a: "0x11", f:
		[
			{name:"OUT1S",  m:"0x03", p:shift_test},
			{name:"OUT2S",  m:"0x1c", p:shift_test},
		]
	},
	{_group_name:"int", a:"0x12", f:
		[
			{name:"CEB",  m:"0x80", p:shift_test},
			{name:"IM",   m:"0x60", p:shift_test},
			{name:"BLIE", m:"0x10", p:shift_test},
			{name:"TIE",  m:"0x08", p:shift_test},
			{name:"AIE",  m:'0x04', p:shift_test},
			{name:"EX2E", m:"0x02", p:shift_test},
			{name:"EX1E", m:"0x01", p:shift_test},
		]
	},
	{_group_name:"sqw", a: "0x13", f:
		[
			{name:"SQWE",  m:"0x60", p:shift_test},
			{name:"SQFS",  m:"0x1F", p:shift_test},
		]
	},
	{_group_name:"calibration", register_name:"calibration_xt", a: "0x14", f:
		[
			{name:"CMDX",    m:"0x80", p:shift_test},
			{name:"OFFSETX", m:"0x7F", p:shift_test},

			{name:"CMDR",     a:"0x15", m:"0xC0", p:shift_test},
			{name:"OFFSETRU", a:"0x15", m:"0x3F", p:shift_test},
			{name:"OFFSETRL", a:"0x16", m:"0xFF", p:shift_test},
		],
		reg:
		[
			{name:"calibration_rc_upper", a:"0x15"},
			{name:"calibration_rc_lower", a:"0x16"},
		]
	},
	{_group_name:"sleep", a: "0x17", f:
		[
			{name:"SLP",   m:"0x80", p:shift_test},
			{name:"SLRES", m:"0x40", p:shift_test},
			{name:"EX2P",  m:"0x20", p:shift_test},
			{name:"EX1P",  m:"0x10", p:shift_test},
			{name:"SLST",  m:"0x08", p:shift_test},
			{name:"SLTO",  m:"0x07", p:shift_test},
		]
	},
	{_group_name:"timer", a: "0x18", f:
		[
			{name:"TE",   m:"0x80", p:shift_test},
			{name:"TM",   m:"0x40", p:shift_test},
			{name:"TRPT", m:"0x20", p:shift_test},
			{name:"RPT",  m:"0x1C", p:shift_test},
			{name:"TFS",  m:"0x03", p:shift_test},

			{name:"countdown",  a:"0x19", m:"0xFF", p:shift_test},

			{name:"initial_value",  a:"0x1A", m:"0xFF", p:shift_test},

			
			{name:"WDS",  a:"0x1B", m:"0x80", p:shift_test},
			{name:"BMB",  a:"0x1B", m:"0x7C", p:shift_test},
			{name:"WRB",  a:"0x1B", m:"0x03", p:shift_test},
		],
		reg:
		[
			{name:"watchdog_timer", a:"0x1B"},
		
		]

	},
	{_group_name:"oscillator", register_name:"oscillator_cont", a: "0x1C", f:
		[
			{name:"OSEL", m:"0x80", p:shift_test},
			{name:"ACAL", m:"0x60", p:shift_test},
			{name:"AOS",  m:"0x10", p:shift_test},
			{name:"FOS",  m:"0x08", p:shift_test},
			{name:"PWGT", m:"0x04", p:shift_test},
			{name:"OFIE", m:"0x02", p:shift_test},
			{name:"ACIE", m:"0x01", p:shift_test},

			{name:"XTCAL", a:"0x1D", m:"0xC0", p:shift_test},
			{name:"LKO2",  a:"0x1D", m:"0x20", p:shift_test},
			{name:"OMODE", a:"0x1D", m:"0x10", p:shift_test},
			{name:"OF",    a:"0x1D", m:"0x02", p:shift_test},
			{name:"ACF",   a:"0x1D", m:"0x01", p:shift_test},
		],
		reg:
		[
			{name:"oscillator_status", a:"0x1D"},
		
		]
		
	},

	{_group_name:"configuration_key", a: "0x1F", f:
		[
		]
	},
	{_group_name:"trickle", a: "0x20", f:
		[
			{name:"TCS",   m:"0xF0", p:shift_test},
			{name:"DIODE", m:"0x0C", p:shift_test},
			{name:"ROUT",  m:"0x03", p:shift_test},
		]
	},
	{_group_name:"bref_control", a: "0x21", f:
		[
			{name:"BREF",  m:"0x0F", p:shift_test},
		]
	},
	{_group_name:"afctrl", a: "0x26", f:
		[
		]
	},
	{_group_name:"batmode_io", a: "0x27", f:
		[
			{name:"IOBM", m:"0x80", p:shift_test},
		]
	},
	{_group_name:"analog_status", a: "0x2F", mode:read_only, f:
		[
			{name:"BBOD", m:"0x80", p:shift_test},
			{name:"BMIN", m:"0x40", p:shift_test},
			{name:"VINIT", m:"0x02", p:shift_test},
		]
	},
	{_group_name:"output_control", a: "0x30", f:
		[
			{name:"WDBM", m:"0x80", p:shift_test},
			{name:"EXBM", m:"0x40", p:shift_test},
			{name:"WDDS", m:"0x20", p:shift_test},
			{name:"EXDS", m:"0x10", p:shift_test},
			{name:"RSEN", m:"0x08", p:shift_test},
			{name:"O4EN", m:"0x04", p:shift_test},
			{name:"O3EN", m:"0x02", p:shift_test},
			{name:"O1EN", m:"0x01", p:shift_test},
		]
	},
	{_group_name:"clock_id", a: "0x28", mode:read_only, f:
		[
			{name:"PN3", m:"0xF0", p:shift_test},
			{name:"PN2", m:"0x0F", p:shift_test},

			{name:"PN1", a:"0x29", m:"0xF0", p:shift_test},
			{name:"PN0", a:"0x29", m:"0x0F", p:shift_test},

			{name:"REV_MAJOR", a:"0x2A", m:"0xF0", p:shift_test},
			{name:"REV_MINOR", a:"0x2A", m:"0x0F", p:shift_test},

			{name:"SERIAL", a:"0x00", m:"0x00", mode:custom_read_only, p:shift_test},

		]
	},
#	{_group_name:"", a: "0x", f:
#		[
#			{name:"", m:"0x", p:shift_test},
#		]
#	},
	{_group_name:"extention_ram", a: "0x3F", f:
		[
			{name:"O4BM", m:"0x80", p:shift_test},
			{name:"BPOL", m:"0x40", p:shift_test},
			{name:"WDIN", m:"0x20", mode:read_only, p:shift_test},
			{name:"EXIN", m:"0x10", mode:read_only, p:shift_test},
			{name:"XADA", m:"0x04", p:shift_test},
			{name:"XADS", m:"0x03", p:shift_test},
		]
	},
#	{_group_name:"", a: "0x", f:
#		[
#			{name:"", m:"0x", p:shift_test},
#		]
#	},
#	{_group_name:"", a: "0x", f:
#		[
#			{name:"", m:"0x", p:shift_test},
#		]
#	},
#	{_group_name:"", a: "0x", f:
#		[
#			{name:"", m:"0x", p:shift_test},
#		]
#	},
]

#ap_map=[ap_map[5], ap_map[8]]

_ap_map=[
	{_group_name:"oscillator", register_name:"oscillator_control", a: "0x1C", f:
		[
			{name:"OSEL", m:"0x80", p:shift_test},
			{name:"ACAL", m:"0x60", p:shift_test},
			{name:"AOS",  m:"0x10", p:shift_test},
			{name:"FOS",  m:"0x08", p:shift_test},
			{name:"PWGT", m:"0x04", p:shift_test},
			{name:"OFIE", m:"0x02", p:shift_test},
			{name:"ACIE", m:"0x01", p:shift_test},

			{name:"XTCAL", a:"0x1D", m:"0xC0", p:shift_test},
			{name:"LKO2",  a:"0x1D", m:"0x20", p:shift_test},
			{name:"OMODE", a:"0x1D", m:"0x10", p:shift_test},
			{name:"OF",    a:"0x1D", m:"0x02", p:shift_test},
			{name:"ACF",   a:"0x1D", m:"0x01", p:shift_test},
		],
		reg:
		[
			{name:"oscillator_status", a:"0x1D"},
		
		]
		
	},
	{_group_name:"configuration_key", a: "0x1F", f:
		[
			#{name:"ACF",   a:"0x1D", m:"0x01", p:shift_test},
		]
	},

]

def ffs(v):
	"""
	https://graphics.stanford.edu/~seander/bithacks.html#IntegerLog
	"""
	#print v, ((v & -v) * 0x077CB531) >> 27
	#MultiplyDeBruijnBitPosition = [  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9]
	#return MultiplyDeBruijnBitPosition[((v & -v) * 0x077CB531) >> 27]
	return libc.ffs(v) 

def msb(val):
	return val.bit_length() - 1

func_bit_flag_template_RW = """
ssize_t show_ab08xx_{group}_{name}(struct device *dev, struct device_attribute *attr, char *buf)
{{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, {address}U, data) < 0)
        {{
                return sprintf(buf, "Error occoured when reading clock.");
        }}
        return sprintf(buf, "%i", {post});

}}

ssize_t store_ab08xx_{group}_{name}(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
	u8 mask = {mask};
        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {{
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        }} else {{
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }}

        if (usr < 0 || usr > 0xffff)
	{{
                return -EINVAL;
	}}


        if(ab08xx_read_reg(ab08xx, {address}U, data) < 0)
        {{
		printk(KERN_INFO "Error occoured when reading clock.\\n");		
        }}

	data[0] = (data[0] & (~mask)) | (usr << {shift});
	ab08xx_write_reg(ab08xx, {address}U, data[0]);	
//	printk(KERN_INFO "Write Reg: %i\\n", data[0]);		
	
        return count;
}}

static ab08xx_DEVICE_ATTR({group}, {name}, S_IWUSR | S_IRUGO, show_ab08xx_{group}_{name}, store_ab08xx_{group}_{name});

"""

func_bit_flag_template_RO = """
ssize_t show_ab08xx_{group}_{name}(struct device *dev, struct device_attribute *attr, char *buf)
{{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, {address}U, data) < 0)
        {{
                return sprintf(buf, "Error occoured when reading clock.");
        }}
        return sprintf(buf, "%i", {post});

}}

static ab08xx_DEVICE_ATTR_RO({group}, {name}, show_ab08xx_{group}_{name});

"""

func_bit_flag_template_custom_RO = """

static ab08xx_DEVICE_ATTR_RO({group}, {name}, show_ab08xx_{group}_{name});

"""

func_reg_template = """
ssize_t show_ab08xx_{group}(struct device *dev, struct device_attribute *attr, char *buf)
{{

        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        u8 data[1];
        if(ab08xx_read_reg(ab08xx, {address}, data) < 0)
        {{
                return sprintf(buf, "Error occoured when reading clock.");
        }}
        return sprintf(buf, "%i", data[0]);

}}

ssize_t store_ab08xx_{group}(struct device *dev, struct device_attribute *attr,
                          const char *buf, size_t count)
{{
        struct ab08xx_t*   ab08xx = dev_get_drvdata(&to_rtc_device(dev)->dev);

        int usr = -1;

        if (buf[0] == '0' && (buf[1] == 'x' || buf[1] == 'X')) {{
                if (sscanf(buf, "%x", &usr) != 1)
                        return -EINVAL;
        }} else {{
                if (sscanf(buf, "%d", &usr) != 1)
                        return -EINVAL;
        }}

        if (usr < 0 || usr > 0xffff)
	{{
                return -EINVAL;
	}}

	printk(KERN_INFO "Write Reg: %i\\n", usr);		
	ab08xx_write_reg(ab08xx, {address}U, usr);	
	
        return count;
}}

static DEVICE_ATTR({group}, S_IWUSR | S_IRUGO, show_ab08xx_{group}, store_ab08xx_{group});

"""

sysfs_attributes="""
static const struct attribute *ab08xx_{name}_attrs[] = {{
{funcs}
        NULL
}};

static const struct attribute_group ab08xx_{name} = {{
        .attrs =   (struct attribute **)&ab08xx_{name}_attrs,
        .name = "{name}",
}};
"""

sysfs_groups_table="""
static const struct attribute_group *ab08xx_groups[] = {{
{funcs}
        NULL
}};

"""

register_group="""
{functions}
{attributes}
"""

master="""
#define ab08xx_DEVICE_ATTR(_group, _name, _mode, _show, _store) \
        struct device_attribute dev_attr_##ab08xx_##_group##_##_name = __ATTR(_name, _mode, _show, _store)

#define ab08xx_DEVICE_ATTR_RO(_group, _name, _show) \
	struct device_attribute dev_attr_##ab08xx_##_group##_##_name = {{	\
		.attr   = {{ .name = __stringify(_name), .mode = S_IRUGO }},	\
		.show   = _show,						\
	}};
{a}
{group}
"""

func_bit_flag_template={
	read_only: func_bit_flag_template_RO,
	read_write: func_bit_flag_template_RW,		
	custom_read_only: func_bit_flag_template_custom_RO,
}
addresses=[]
code=[]
groups=[]
for group in ap_map:
	group_name=group[_group_name]
	group_addr = group[a]
	groups.append("\t&ab08xx_{name},".format(name=group_name))
	attrs=[]
	funcs=[]

	#Set the rgname here so that if there are no flags the grname is correct
	rgname = group_name
	if register_name in group:
		rgname = group[register_name]

	group_perms = read_write
	if mode in group:
		group_perms = group[mode]

	for flag in group[f]:

		reg_mode = group_perms
		if mode in flag:
			reg_mode = flag[mode]

		flag_addr = group_addr
		if a in flag:
			flag_addr = flag[a]

		shift = (ffs(int(flag[m], 16)) - 1 )
		flag_name = flag[name]
		mask = flag[m]

		_p = flag[p].format(value="data[0]", mask=mask, shift=shift)

		attrs.append("\t&dev_attr_ab08xx_{name}.attr,".format(name="{}_{}".format(group_name, flag_name)))
		funcs.append(func_bit_flag_template[reg_mode].format(group=group_name, name=flag_name, address=flag_addr, mask=mask, post=_p, shift=shift))

	funcs.append(func_reg_template.format(group=rgname, address=flag_addr))
	attrs.append("\t&dev_attr_{reg_name}.attr,".format(reg_name=rgname))

#	for groups like calibration that are made up of multiple registers, we will add an extra file for each register.
	if reg in group:
		for extra_reg in group[reg]:
			funcs.append(func_reg_template.format(group=extra_reg[name], address=extra_reg[a]))
			attrs.append("\t&dev_attr_{reg_name}.attr,".format(reg_name=extra_reg[name]))

	code.append(register_group.format(functions="\n".join(funcs), attributes=sysfs_attributes.format(funcs="\n".join(attrs), name=group_name)))


print master.format(a="".join(code), group=sysfs_groups_table.format(funcs="\n".join(groups)))

