obj-m += ab08xx-spi.o
linux_src=/home/pi/linux
all:
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	make -C $(linux_src) M=$(PWD) modules

clean:
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	make -C $(linux_src) M=$(PWD) clean
