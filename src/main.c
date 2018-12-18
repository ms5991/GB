#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"


int main(int argc, char const *argv[])
{
    cpu_t c;
    mem_t m;
    initCpu(&c);
    printFlags(&c);
    printRegs(&c);
    executeOpcode(0x4, &c, &m);
    executeOpcode(0x4, &c, &m);
    printRegs(&c);

    return 0;
}






