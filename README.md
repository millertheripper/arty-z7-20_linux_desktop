# Arty-Z7-20
* Petalinux Display with Desktop based on AXI framebuffer read

## Base HDMI Project derived from 
* https://github.com/DuyTrandeLion/PYNQ-Z1
* Thanks to Duy for Supporting!!

## Xilinx Tools Version: 2020.2

## Requirements:
------------
* **Arty Z7-20**
* **Vivado and Petalinux Installation**
* **Installation of Arty Z7-20 Board files**
* **Serial Terminal Emulator Application**
* **MicroUSB Cable**
* **HDMI Capable Monitor/TV**
* **SD Card with FAT32 and EXT4 Partitions**

## Install board files
------
```bash
make install_board_files
```

## Compile project:
------
Compile everything: 
```bash
make
```

Create and compile Vivado project: 
```bash
make fpga
```

Create and compile Vitis bare metal project, create boot binary
```bash
make vitis
```

Create and compile petalinux project
```bash
make petalinux
```

Applying changes:
------
Vivado Block Design: From tcl shell:
```bash
write_bd_tcl [get_property DIRECTORY [current_project]]/../source/scripts/bd.tcl -include_layout -force
```

Software Design (Vitis): Put vitis source code under:
* Put all files in ./vitis/src 

BSP directory structure: 
------
```bash
├── build                       <--- Build Outputs (FPGA and Boot binaries)
├── hw                          <--- All source files related to Vivado Design 
│   ├── build                   <--- Vivado Project  
│   ├── scripts                 <--- TCL scripts to recreate project in batch mode
│   │   └── settings.tcl        <--- Set FPGA type, project name, and number of processors for compilation 
│   └── source
│       ├── constraints         <--- Constraints location. Files will be imported during creation
│       ├── hdl                 <--- Put HDL IP blocks (non block design) here
│       ├── ip                  <--- Put IP blocks (used by ip integrator) here
│       └── scripts
│           └── bd.tcl          <--- TCL script to recreate the block design.
└── sw
    ├── petalinux               <--- Petalinux project 
    ├── vitis                   <--- Project folder containing bare metal application 
    │   ├── build               <--- Boot image is located here (BOOT.bin)
    │   ├── scripts             <--- TCL scripts for batch mode
    │   ├── src                 <--- Bare metal source code files
    │   └── ws                  <--- Vitis workspace
    └── xsa                     <--- Hardware description file, exported by vivado
```
## Copy files to SD card (FAT32 and EXT4 Partition required for RootFS)
```bash
cp sw/petalinux/images/{BOOT.bin,image.ub,boot.scr} /media/hbrs/BOOT
sudo tar -xvzf sw/petalinux/images/linux/rootfs.tar.gz -C /media/hbrs/root
```