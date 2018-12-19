#ifndef _CPU_H
#define _CPU_H

#include "components.h"

void initCpu(cpu_t* cpu);

flag_value_t getFlag(cpu_t* cpu, flags_t flag);
void setFlag(cpu_t* cpu, flags_t flag, flag_value_t value);

void executeOpcode(uint8_t opcode, cpu_t* cpu, mem_t* mem);

void incrementEightBitReg(
    cpu_t* cpu,
    uint8_t* reg,
    uint8_t currentRegVal);

void decrementEightBitReg(
    cpu_t* cpu,
    uint8_t* reg,
    uint8_t currentRegVal);

void addEightBitRegisters(
    cpu_t* cpu,
    uint8_t* resultReg,
    uint8_t reg1,
    uint8_t reg2);

void subtractEightBitRegisters(
    cpu_t* cpu,
    uint8_t* resultReg,
    uint8_t reg1,
    uint8_t reg2);


void printFlags(cpu_t* cpu);
void printRegs(cpu_t* cpu);

#endif