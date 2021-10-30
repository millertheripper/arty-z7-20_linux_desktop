# Arty-Z7-20 HDMI Out
* Petalinux Display with Desktop based on AXI framebuffer read

## Base HDMI Project derived from 
* https://github.com/DuyTrandeLion/PYNQ-Z1
* Thanks to Duy for Supporting!!

## Xilinx Tools Version: 2020.2

## Requirements:
------------
* **Arty Z7-20**
* **Vivado and Petalinux Installation**
* **Serial Terminal Emulator Application**
* **MicroUSB Cable**
* **HDMI Capable Monitor/TV**
* **SD Card with FAT32 and EXT4 Partitions**

## How to build project
```bash
make
```

# Revision control
## From Vivado tcl shell: 
```bash
write_bd_tcl [get_property DIRECTORY [current_project]]/../source/scripts/bd.tcl -include_layout -force
```
## Copy files to SD card (FAT32 and EXT4 Partition required for RootFS)
```bash
cp sw/petalinux/images/{BOOT.bin,image.ub,boot.scr} /media/hbrs/BOOT
sudo tar -xvzf sw/petalinux/images/linux/rootfs.tar.gz -C /media/hbrs/root
```