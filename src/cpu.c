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


typedef uint8_t (*result_flag_calc_t)(uint8_t result, uint8_t op1, uint8_t op2, alu_op_t aluOp);

uint8_t isZero(
    uint8_t result, 
    uint8_t op1, 
    uint8_t op2, 
    alu_op_t alu_operation)
{
    // does not depend on alu operation
    return result == 0;
}

uint8_t isCarry(
    uint8_t result, 
    uint8_t op1,
    uint8_t op2, 
    alu_op_t alu_operation)
{
    // carry is different between add and sub
    switch (alu_operation)
    {
        case ALU_ADD:
            return result < op1;
        case ALU_SUB:
            return result > op1;
        default:
            return 0;
    }

}

uint8_t isHalfCarry(
    uint8_t result, 
    uint8_t op1, 
    uint8_t op2, 
    alu_op_t alu_operation)
{
    switch (alu_operation)
    {
        case ALU_ADD:
            return (((op1 & 0xf) + (op2 & 0xf)) & 0x10) == 0x10;
        case ALU_SUB:
            return (((result & 0xF) - (op1 & 0xF)) < 0);
        default:
            return 0;
    }
}

void calculateAndSetFlag(
    cpu_t* cpu,
    flags_t flag,
    flag_operation_t flagOp,
    result_flag_calc_t flagCalc,
    uint8_t result,
    uint8_t op1,
    uint8_t op2,
    alu_op_t aluOp)
{
    // if the flag is unaffected, return
    if (flagOp == OP_FLAG_NO_OP)
        return;

    flag_value_t toSet = FLAG_NOT_SET;
    switch (flagOp)
    {
        // flag is not set
        case OP_FLAG_SET_OFF:
            toSet = FLAG_NOT_SET;
            break;
        // flag is set
        case OP_FLAG_SET_ON:
            toSet = FLAG_SET;
            break;
        // flag is toggled to the opposite of it's current value
        case OP_FLAG_TOGGLE:
            toSet = getFlag(cpu, flag) == FLAG_NOT_SET ? FLAG_SET : FLAG_NOT_SET;
            break;
        // flag is set according to the result of the operation as determined by flagCalc
        case OP_FLAG_PER_RESULT:
            toSet = flagCalc(result, op1, op2, aluOp) ? FLAG_SET : FLAG_NOT_SET;
            break;
        default:
            // included to avoid compile warning
            break;
    }

    // set the value of the flag
    setFlag(cpu, flag, toSet);
}

void calculateAndSetAllFlags(
    cpu_t* cpu,
    uint8_t* result, 
    uint8_t op1, 
    uint8_t op2, 
    flag_operation_t zFlagZeroOp,
    flag_operation_t nFlagSubOp,
    flag_operation_t hFlagHalfCarryOp,
    flag_operation_t cFlagCarryOp,
    alu_op_t aluOp)
{
    calculateAndSetFlag(cpu, flag_Z, zFlagZeroOp, &isZero, *result, op1, op2, aluOp);
    calculateAndSetFlag(cpu, flag_N, nFlagSubOp, NULL, *result, op1, op2, aluOp);
    calculateAndSetFlag(cpu, flag_H, hFlagHalfCarryOp, &isHalfCarry, *result, op1, op2, aluOp);
    calculateAndSetFlag(cpu, flag_C, cFlagCarryOp, &isCarry, *result, op1, op2, aluOp);
}

void performEightBitAddition(
    cpu_t* cpu,
    uint8_t* result, 
    uint8_t op1, 
    uint8_t op2, 
    flag_operation_t zFlagZeroOp,
    flag_operation_t nFlagSubOp,
    flag_operation_t hFlagHalfCarryOp,
    flag_operation_t cFlagCarryOp)
{
    // set the result
    *result = op1 + op2;

    // calculate and set the flags
    calculateAndSetAllFlags(cpu, result, op1, op2, zFlagZeroOp, nFlagSubOp, hFlagHalfCarryOp, cFlagCarryOp, ALU_ADD);
}

void performEightBitSubtraction(
    cpu_t* cpu,
    uint8_t* result,
    uint8_t op1,
    uint8_t op2,
    flag_operation_t zFlagZeroOp,
    flag_operation_t nFlagSubOp,
    flag_operation_t hFlagHalfCarryOp,
    flag_operation_t cFlagCarryOp)
{
    *result = op1 - op2;

    // calculate and set the flags
    calculateAndSetAllFlags(cpu, result, op1, op2, zFlagZeroOp, nFlagSubOp, hFlagHalfCarryOp, cFlagCarryOp, ALU_SUB);
}


void incrementEightBitReg(
    cpu_t* cpu,
    uint8_t* reg,
    uint8_t currentRegVal)
{
    // increment is adding 1 to current value.
    // all increments affect flags Z, N, and H
    performEightBitAddition(cpu, reg, currentRegVal, 1, OP_FLAG_PER_RESULT, OP_FLAG_SET_OFF, OP_FLAG_PER_RESULT, OP_FLAG_NO_OP);
}

void decrementEightBitReg(
    cpu_t* cpu,
    uint8_t* reg,
    uint8_t currentRegVal)
{
    // decrement is subtracting 1 from current value.
    // all decrements affect flags Z, N, and H
    performEightBitSubtraction(cpu, reg, currentRegVal, 1, OP_FLAG_PER_RESULT, OP_FLAG_SET_ON, OP_FLAG_PER_RESULT, OP_FLAG_NO_OP);
}

void addEightBitRegisters(
    cpu_t* cpu,
    uint8_t* resultReg,
    uint8_t reg1,
    uint8_t reg2)
{
    performEightBitAddition(cpu, resultReg, reg1, reg2, OP_FLAG_PER_RESULT, OP_FLAG_SET_OFF, OP_FLAG_PER_RESULT, OP_FLAG_PER_RESULT);
}

void subtractEightBitRegisters(
    cpu_t* cpu,
    uint8_t* resultReg,
    uint8_t reg1,
    uint8_t reg2)
{
    performEightBitSubtraction(cpu, resultReg, reg1, reg2, OP_FLAG_PER_RESULT, OP_FLAG_SET_ON, OP_FLAG_PER_RESULT, OP_FLAG_PER_RESULT);
}



void executeOpcode(uint8_t opcode, cpu_t* cpu, mem_t* mem)
{
   normalOpcodes[opcode](cpu, mem);
}

flag_value_t getFlag(cpu_t* cpu, flags_t flag)
{
    if (cpu->reg_F & flag)
       return FLAG_SET;
    return FLAG_NOT_SET;
}


void setFlag(cpu_t* cpu, flags_t flag, flag_value_t value)
{
    if (value == FLAG_SET)
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