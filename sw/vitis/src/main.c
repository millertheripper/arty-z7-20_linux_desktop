/* INCLUDE */
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

/* MAIN CODE */
int main(void)
{
	init_platform();

    print("Hello World\n\r");

    cleanup_platform();
    return 0;
}
