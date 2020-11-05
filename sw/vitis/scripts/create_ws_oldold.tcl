setws .

#domain active standalone_domain
#platform generate

# Generate ZYNQ FSBL
app create -name fsbl -platform [lindex $argv 0] -domain standalone_domain -template {Zynq FSBL} 
app config -name fsbl define-compiler-symbols {FSBL_DEBUG_INFO}
app config -name fsbl define-compiler-symbols {FSBL_DEBUG}
rm design_1_wrapper/ps7_cortexa9_0/standalone_domain/bsp/ps7_cortexa9_0/libsrc/ddynclk_v1_0/src/ddynclk_g.c
app build -name fsbl.


# Create Application template and import sources as soft link
app create -name app -platform [lindex $argv 0] -domain standalone_domain -template {Empty Application}
importsources -name app -path [lindex $argv 1] -soft-link

# Set project settings per build configuration
app config -set -name app build-config Release
app config -set -name app assembler-flags {}
app config -set -name app compiler-misc {-c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard}
app config -set -name app compiler-optimization {Optimize more (-O2)}
app config -add -name app include-path [lindex $argv 1]
app config -set -name app linker-script [lindex $argv 1]/lscript.ld

app config -set -name app build-config Debug
app config -set -name app assembler-flags {}
app config -set -name app compiler-misc {-c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard}
app config -set -name app compiler-optimization {None (-O0)}
app config -add -name app include-path [lindex $argv 1]
app config -set -name app linker-script [lindex $argv 1]/lscript.ld
app build -name app

exit
