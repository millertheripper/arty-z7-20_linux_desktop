include Makefile.inc

.PHONY: all
all: fpga vitis petalinux

.PHONY: vitis
vitis:
	$(MAKE) -C sw/vitis

.PHONY: petalinux
petalinux:
	$(MAKE) -C sw/petalinux

.PHONY: fpga
fpga:
	$(MAKE) -C hw

.PHONY: clean
clean:
	$(MAKE) -C hw clean
	$(MAKE) -C sw/petalinux clean
	@rm -rf *.str *.log *.jou .Xil