VERSION ?= 2020.1
PETALINUX := source /opt/Xilinx/petalinux-v$(VERSION)/settings.sh &&
DISTDIR := $(shell pwd)/../../build/petalinux

.PHONY: all
all: update-fpga BOOT_BIN dist

.PHONY: BOOT_BIN
BOOT_BIN: petalinux 	
	$(PETALINUX) petalinux-package --boot --fpga --u-boot --force

.PHONY: petalinux
petalinux:
	$(PETALINUX) petalinux-config --silentconfig
	$(PETALINUX) petalinux-build

.PHONY: clean
clean:
	$(PETALINUX) petalinux-build -x mrproper -f

.PHONY: update-fpga
update-fpga:
	$(PETALINUX) petalinux-config --silentconfig --get-hw-description ../xsa/

.PHONY: dist
dist: 	
	mkdir -p ${DISTDIR}
	cp $(shell pwd)/images/linux/{boot.scr,BOOT.BIN,image.ub,rootfs.tar.gz} ${DISTDIR} 
