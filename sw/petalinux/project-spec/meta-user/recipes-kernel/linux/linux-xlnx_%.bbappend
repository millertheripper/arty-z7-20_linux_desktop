FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://devtool-fragment.cfg \
	    file://pynqz1-display-lion.cfg \
	    file://pynqz1-display.patch \
	   "

