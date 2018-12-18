#include "cpu.h"
#include "opcodes.h"
#include <stdio.h>

void initCpu(cpu_t* cpu)
{
    cpu->reg_PC = 0;
    cpu->reg_SP = 0;
    cpu->reg_A = 0;
    cpu->reg_F = 0;
    cpu->reg_B = 0;
    cpu->reg_C = 0;
    cpu->reg_D = 0;
    cpu->reg_E = 0;
    cpu->reg_H = 0;
    cpu->reg_L = 0;
}

void executeOpcode(uint8_t opcode, cpu_t* cpu, mem_t* mem)
{
   normalOpcodes[opcode](cpu, mem);
}

flagValue_t getFlag(cpu_t* cpu, flags_t flag)
{
    if (cpu->reg_F & flag)
       return SET;
    return NOT_SET;
}

void setFlags(cpu_t* cpu, flagValue_t z_value, flagValue_t n_value, flagValue_t h_value, flagValue_t c_value)
{
    setFlag(cpu, flag_Z, z_value);
    setFlag(cpu, flag_N, n_value);
    setFlag(cpu, flag_H, h_value);
    setFlag(cpu, flag_C, c_value);
}

void setFlag(cpu_t* cpu, flags_t flag, flagValue_t value)
{
    if (value == SET)
    {
        // flag is always for the intended flag, so this sets it to 1
        cpu->reg_F = cpu->reg_F | flag;
    }
    else
    {
        // set it to zero
        cpu->reg_F = cpu->reg_F & (~flag);
    }
}

void printFlags(cpu_t* cpu)
{
    printf("Flags:\n");
    printf("\tZ: %u\n",getFlag(cpu, flag_Z));
    printf("\tN: %u\n",getFlag(cpu, flag_N));
    printf("\tH: %u\n",getFlag(cpu, flag_H));
    printf("\tC: %u\n",getFlag(cpu, flag_C));
}
void printRegs(cpu_t* cpu)
{
    printf("Registers:\n");
    printf("\tA: %u\n",cpu->reg_A);
    printf("\tF: %u\n",cpu->reg_F);
    printf("\tB: %u\n",cpu->reg_B);
    printf("\tC: %u\n",cpu->reg_C);
    printf("\tD: %u\n",cpu->reg_D);
    printf("\tE: %u\n",cpu->reg_E);
    printf("\tH: %u\n",cpu->reg_H);
    printf("\tL: %u\n",cpu->reg_L);
}