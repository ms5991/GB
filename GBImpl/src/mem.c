#include "mem.h"
#include "opcodes.h"
#include <stdio.h>

void initMem(
    mem_t* mem)
{
    for (int i=0;i<RAM_SIZE;i++)
    {
        mem->ram[i] = 0;
    }
}

uint8_t fetchEightBitMem(
    mem_t* mem,
    uint16_t addr)
{
    return mem->ram[addr];
}

uint8_t setEightBitMem(
    mem_t* mem,
    uint16_t addr,
    uint8_t value)
{
    return mem->ram[addr] = value;
}