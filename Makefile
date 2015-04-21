MOD_NAME= ab08xx-spi
obj-m += ab08xx-spi.o
CURRENT = $(shell uname -r)
DEST = /lib/modules/$(CURRENT)/kernel/drivers/rtc/
# ccflags-y+=" -save-temps "

SUBDIRS = devicetree

all: $(SUBDIRS) ab08xx-spi-sysfs.c
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules EXTRA_CFLAGS="-save-temps"

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@


clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

	for i in $(SUBDIRS); do\
		$(MAKE) -C $$i clean ;\
	done

install: 
	cp $(MOD_NAME).ko $(DEST)
	depmod -a
	for i in $(SUBDIRS); do\
		$(MAKE) -C $$i install ;\
	done

ab08xx-spi-sysfs.c:
	./gen.py > ab08xx-spi-sysfs.c
	
