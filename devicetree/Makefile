DTC=dtc

all: ab0815-spi-rpi-overlay.dtb ab0815-spi-bitbang-rpi-overlay.dtb

ab0815-spi-rpi-overlay.dtb: ab0815-spi-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-rpi-overlay.dtb ab0815-spi-rpi-overlay.dts	

ab0815-spi-bitbang-rpi-overlay.dtb: ab0815-spi-bitbang-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-bitbang-rpi-overlay.dtb ab0815-spi-bitbang-rpi-overlay.dts

clean: 
	rm -f *.dtb

install: ab0815-spi-rpi-overlay.dtb ab0815-spi-bitbang-rpi-overlay.dtb
	echo "INSTALLING DEVICETREE"
	cp ab0815-spi-rpi-overlay.dtb /boot/overlays/
	cp ab0815-spi-bitbang-rpi-overlay.dtb /boot/overlays/
