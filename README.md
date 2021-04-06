# Arty-Z7-20 HDMI Demo
* Added C implementation of sobel filter

## Base HDMI Project derived from 
https://github.com/Digilent/Arty-Z7-20-hdmi-in/tree/v2020.1

This project demonstrates how to use HLS (High Level Synthesis) language to create image filters (Sobel-Filter, Edge Detection). The HLS logic is exported as 
IP core and inserted into the video block design AXI stream.

| Option    | Function                                                                                                                 |
| --------- | ------------------------------------------------------------------------------------------------------------------------ |
| 1         | Change the resolution of the HDMI output to the monitor.                                                                 |
| 2         | Change the frame buffer to display on the HDMI monitor.                                                                  |
| 3/4       | Store a test pattern in the chosen video frame buffer - color bar or blended.                                            |
| 5         | Start/Stop streaming video data from HDMI to the chosen video frame buffer.                                              |
| 6         | Change the video frame buffer that HDMI data is streamed into.                                                           |
| 7         | Invert and store the current video frame into the next video frame buffer and display it.                                |
| 8         | Scale the current video frame to the display resolution, store it into the next video frame buffer, and then display it. |
| 9         | Grab Video Frame and perform sobel filter.                                                                               |


## Requirements
------------
* **Arty Z7-20**
* **Vivado and Vitis 2020.1 Installations**
* **Vitis Video Library** 
* **Open CV 3.3.0 installation**
* **Serial Terminal Emulator Application**
* **MicroUSB Cable**
* **2 HDMI Cables**
* **HDMI Capable Monitor/TV**
* **HDMI Capable Source** (likely the computer used for Vivado and Vitis)

## How to build project
- make

# Revision control
## From Vivado tcl shell: 
- write_bd_tcl [get_property DIRECTORY [current_project]]/../source/scripts/bd.tcl -include_layout -force

## Vitis source files:
- ./sw/vitis/src