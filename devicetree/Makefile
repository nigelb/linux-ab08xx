DTC=dtc
OVERLAY_DIR=/boot/overlays/
all: ab0815-spi-rpi-overlay.dtb ab0815-spi-bitbang-rpi-overlay.dtb ab0815-spi-cs-gpio-rpi-overlay.dtb

ab0815-spi-rpi-overlay.dtb: ab0815-spi-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-rpi-overlay.dtb ab0815-spi-rpi-overlay.dts	

ab0815-spi-bitbang-rpi-overlay.dtb: ab0815-spi-bitbang-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-bitbang-rpi-overlay.dtb ab0815-spi-bitbang-rpi-overlay.dts

ab0815-spi-cs-gpio-rpi-overlay.dtb: ab0815-spi-cs-gpio-rpi-overlay.dts
	$(DTC) -@ -I dts -O dtb -o ab0815-spi-cs-gpio-rpi-overlay.dtb ab0815-spi-cs-gpio-rpi-overlay.dts 

clean: 
	rm -f *.dtb

install: install-msg install-ab0815-spi-rpi-overlay.dtb install-ab0815-spi-bitbang-rpi-overlay.dtb install-ab0815-spi-cs-gpio-rpi-overlay.dtb

install-msg:
	echo "INSTALLING DEVICETREE"

install-ab0815-spi-rpi-overlay.dtb: ab0815-spi-rpi-overlay.dtb
	cp ab0815-spi-rpi-overlay.dtb /boot/overlays/

install-ab0815-spi-bitbang-rpi-overlay.dtb: ab0815-spi-bitbang-rpi-overlay.dtb
	cp ab0815-spi-bitbang-rpi-overlay.dtb /boot/overlays/

install-ab0815-spi-cs-gpio-rpi-overlay.dtb: ab0815-spi-cs-gpio-rpi-overlay.dtb
	cp ab0815-spi-cs-gpio-rpi-overlay.dtb $(OVERLAY_DIR)
	
