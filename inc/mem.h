#ifndef _MEM_H
#define _MEM_H

#include "components.h"


void initMem(
    mem_t* mem
);

uint8_t fetchEightBitMem(
    mem_t* mem,
    uint16_t addr
);

uint8_t setEightBitMem(
    mem_t* mem,
    uint16_t addr,
    uint8_t value
);

#endif