
#ifndef _TEST

#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "mem.h"


int main(int argc, char const *argv[])
{
    cpu_t c;
    mem_t m;
    initCpu(&c);
    initMem(&m);
    printFlags(&c);
    printRegs(&c);
    executeOpcode(0x4, &c, &m);
    executeOpcode(0x4, &c, &m);
    printRegs(&c);


    setEightBitMem(&m, 0x1005, 128);


    return 0;
}

#endif




