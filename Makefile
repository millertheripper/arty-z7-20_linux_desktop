include Makefile.inc

.PHONY: all
all: fpga petalinux

.PHONY: petalinux
	$(MAKE) -C sw/petalinux

.PHONY: fpga
fpga:
	$(MAKE) -C hw

.PHONY: clean
clean:
	$(MAKE) -C hw clean
	$(MAKE) -C sw/petalinux clean
	@rm -rf *.str *.log *.jou .Xil