#ifndef _CPU_H
#define _CPU_H

#include "components.h"

void initCpu(cpu_t* cpu);

flagValue_t getFlag(cpu_t* cpu, flags_t flag);


void setFlags(cpu_t* cpu, flagValue_t z_value, flagValue_t n_value, flagValue_t h_value, flagValue_t c_value);
void setFlag(cpu_t* cpu, flags_t flag, flagValue_t value);

void executeOpcode(uint8_t opcode, cpu_t* cpu, mem_t* mem);

void printFlags(cpu_t* cpu);
void printRegs(cpu_t* cpu);

#endif