include Makefile.inc

.PHONY: all
all: fpga vitis

.PHONY: vitis
vitis:
	$(MAKE) -C sw/vitis

.PHONY: fpga
fpga:
	$(MAKE) -C hw

.PHONY: clean
clean:
	$(MAKE) -C hw clean
	$(MAKE) -C sw/vitis clean
	@rm -rf *.str *.log *.jou .Xil