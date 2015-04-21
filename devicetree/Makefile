DTC=dtc

all: ab0815-spi-rpi-overlay.dtb

ab0815-spi-rpi-overlay.dtb: ab0815-spi-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-rpi-overlay.dtb ab0815-spi-rpi-overlay.dts	

clean: 
	rm -f ab0815-spi-rpi-overlay.dtb

install: ab0815-spi-rpi-overlay.dtb
	echo "INSTALLING DEVICETREE"
	cp ab0815-spi-rpi-overlay.dtb /boot/overlays/
