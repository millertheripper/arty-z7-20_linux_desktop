# Arty-Z7-20 HDMI IN/OUT demo

## Derived from 
https://github.com/Digilent/Arty-Z7-20-hdmi-in/tree/v2020.1

This project demonstrates how to use the USB-UART Bridge, HDMI Sink and HDMI Source with the ZYNQ processor. Vivado is used to build the demo's hardware platform, and Xilinx SDK is used to program the bitstream onto the board and to build and deploy a C application. Video data streams in through the HDMI in port and out through the HDMI out port. A UART interface is available to configure what is output through HDMI.
There are 3 display frame buffers that the user can choose to display or write to. The configuring options are shown in the table below.

The demo uses the usb-uart bridge to configure the HDMI Display , the Arty Z7-20 must be connected to a computer over MicroUSB, which must be running a serial terminal. For more information on how to set up and use a serial terminal, such as Tera Term or PuTTY, refer to [this tutorial](https://reference.digilentinc.com/learn/programmable-logic/tutorials/tera-term).

| Option    | Function                                                                                                                 |
| --------- | ------------------------------------------------------------------------------------------------------------------------ |
| 1         | Change the resolution of the HDMI output to the monitor.                                                                 |
| 2         | Change the frame buffer to display on the HDMI monitor.                                                                  |
| 3/4       | Store a test pattern in the chosen video frame buffer - color bar or blended.                                            |
| 5         | Start/Stop streaming video data from HDMI to the chosen video frame buffer.                                              |
| 6         | Change the video frame buffer that HDMI data is streamed into.                                                           |
| 7         | Invert and store the current video frame into the next video frame buffer and display it.                                |
| 8         | Scale the current video frame to the display resolution, store it into the next video frame buffer, and then display it. |


## Requirements
------------
* **Arty Z7-20**
* **Vivado and Vitis 2020.1 Installations**
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