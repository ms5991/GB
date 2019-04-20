#ifndef _MEM_H
#define _MEM_H

#include "components.h"

void dumpMem(
    mem_t* mem,
    uint16_t upTo
);

void initMem(
    mem_t* mem,
    uint8_t* rom,
    uint16_t romSize
);

uint8_t fetchEightBitMem(
    mem_t* mem,
    uint16_t addr
);

void setEightBitMem(
    mem_t* mem,
    uint16_t addr,
    uint8_t value
);

#endif