setws .

# Create platform and domain 
platform create -name [lindex $argv 0] -hw ./xsa/[lindex $argv 0].xsa -no-boot-bsp 
domain create -name standalone_domain -os standalone -proc ps7_cortexa9_0
domain active standalone_domain
bsp setlib -name xilffs
bsp setlib -name xilsecure
bsp setlib -name xilpm

# Customize BSP, this replaces *.mss file
bsp config clocking "false"
bsp config enable_sw_intrusive_profiling "false"
bsp config hypervisor_guest "false"
bsp config lockstep_mode_debug "false"
bsp config microblaze_exceptions "false"
bsp config predecode_fpu_exceptions "false"
bsp config profile_timer "none"
bsp config sleep_timer "none"
bsp config stdin "ps7_uart_0"
bsp config stdout "ps7_uart_0"
bsp config ttc_select_cntr "2"
bsp config zynqmp_fsbl_bsp "false"
bsp config archiver "arm-none-eabi-ar"
bsp config assembler "arm-none-eabi-as"
bsp config compiler "arm-none-eabi-gcc"
bsp config compiler_flags "-O2 -c"
bsp config extra_compiler_flags "-mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostartfiles -g -Wall -Wextra"

exit
