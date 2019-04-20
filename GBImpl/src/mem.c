#include "mem.h"
#include "opcodes.h"
#include <stdio.h>

void dumpMem(
    mem_t* mem,
    uint16_t upTo)
{
    if (upTo > RAM_SIZE || upTo < 0)
        upTo = RAM_SIZE;

    int i;
    for (i=0;i<upTo;i++)
        printf("%02x\n", mem->ram[i]);
}

void initMemToEmpty(
    mem_t* mem)
{
    for (int i=0;i<RAM_SIZE;i++)
    {
        mem->ram[i] = 0;
    }
}


void initMem(
    mem_t* mem,
    uint8_t* rom,
    uint16_t romSize)
{
    if (rom == NULL || romSize == 0)
    {
        initMemToEmpty(mem);
        return;
    }

    int i;
    for (i=0;i<romSize;i++)
    {
        mem->ram[i] = rom[i];
    }
    for (i=romSize;i<RAM_SIZE;i++)
    {
        mem->ram[i] = 0;
    }
}

int canWrite(uint16_t addr)
{
    return addr > 0x7FFF;
}

uint8_t fetchEightBitMem(
    mem_t* mem,
    uint16_t addr)
{
    return mem->ram[addr];
}

void setEightBitMem(
    mem_t* mem,
    uint16_t addr,
    uint8_t value)
{
    if (!canWrite(addr))
        return; // TODO -- fault?
    mem->ram[addr] = value;
}