#include "cpu.h"
#include "mem.h"
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

uint8_t isZero(
    cpu_t* cpu,
    uint8_t result, 
    uint8_t op1, 
    uint8_t op2, 
    alu_op_t alu_operation)
{
    // does not depend on alu operation
    return result == 0;
}


uint8_t isCarry(
    cpu_t* cpu,
    uint8_t result, 
    uint8_t op1,
    uint8_t op2, 
    alu_op_t alu_operation)
{
    switch (alu_operation)
    {
        case ALU_ADD:
            return result < op1;
        case ALU_ADC:
            // if carry flag is set, account for extra 1 by using <= instead of <
            if (getFlag(cpu, flag_C) == FLAG_SET)
            {
                return result <= op1;
            }
            // carry flag not set, so this is normal addition
            return result < op1;
        case ALU_SUB:
        case ALU_CP:
            return result > op1;
        case ALU_SBC:
            // if carry flag is set, account for extra 1 by using >= instead of >
            if (getFlag(cpu, flag_C) == FLAG_SET)
            {
                return result >= op1;
            }
            // carry flag not set, so this is normal subtraction
            return result > op1;

        default:
            return 0;
    }

}

uint8_t isHalfCarry(
    cpu_t* cpu,
    uint8_t result, 
    uint8_t op1, 
    uint8_t op2, 
    alu_op_t alu_operation)
{
    switch (alu_operation)
    {
        case ALU_ADD:
        case ALU_INC:
        case ALU_ADC:
            return ((op1 ^ op2 ^ result) & 0x10) == 0x10;
        case ALU_SUB:
        case ALU_DEC:
        case ALU_SBC:
        case ALU_CP:
            return ((op1 ^ op2 ^ result) & 0x10) == 0x10;
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
            toSet = flagCalc(cpu, result, op1, op2, aluOp) ? FLAG_SET : FLAG_NOT_SET;
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

void executeEightBitALUOp(
    cpu_t* cpu,
    uint8_t* resultReg,
    uint8_t op1,
    uint8_t op2,
    alu_op_t operation)
{
    flag_operation_t zFlagZeroOp = OP_FLAG_NO_OP;
    flag_operation_t nFlagSubOp = OP_FLAG_NO_OP;
    flag_operation_t hFlagHalfCarryOp = OP_FLAG_NO_OP;
    flag_operation_t cFlagCarryOp = OP_FLAG_NO_OP;
    switch (operation)
    {
        case ALU_INC:

            // perform the operation
            *resultReg = op1 + op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;

            break;
        case ALU_DEC:

            *resultReg = op1 - op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_ON;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            break;
        case ALU_ADD:
            // perform the operation
            *resultReg = op1 + op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            cFlagCarryOp = OP_FLAG_PER_RESULT;

            break;
        case ALU_SUB:

            *resultReg = op1 - op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_ON;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            cFlagCarryOp = OP_FLAG_PER_RESULT;

            break;
        case ALU_AND:

            *resultReg = op1 & op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_SET_ON;
            cFlagCarryOp = OP_FLAG_SET_OFF;

            break;
        case ALU_OR:

            *resultReg = op1 | op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_SET_OFF;
            cFlagCarryOp = OP_FLAG_SET_OFF;

            break;
        case ALU_XOR:

            *resultReg = op1 ^ op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_SET_OFF;
            cFlagCarryOp = OP_FLAG_SET_OFF;
        
            break;
        case ALU_ADC:

            *resultReg = op1 + op2 + (getFlag(cpu, flag_C) == FLAG_SET ? 1 : 0);

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_OFF;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            cFlagCarryOp = OP_FLAG_PER_RESULT;
        
            break;
        case ALU_SBC:

            *resultReg = op1 - op2 - (getFlag(cpu, flag_C) == FLAG_SET ? 1 : 0);

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_ON;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            cFlagCarryOp = OP_FLAG_PER_RESULT;
        
            break;
        case ALU_CP:

            *resultReg = op1 - op2;

            zFlagZeroOp = OP_FLAG_PER_RESULT;
            nFlagSubOp = OP_FLAG_SET_ON;
            hFlagHalfCarryOp = OP_FLAG_PER_RESULT;
            cFlagCarryOp = OP_FLAG_PER_RESULT;
        
            break;
    }

    calculateAndSetAllFlags(cpu, resultReg, op1, op2, zFlagZeroOp, nFlagSubOp, hFlagHalfCarryOp, cFlagCarryOp, operation);
}


void executeLoad(
    uint8_t* destinationReg,
    uint8_t value)
{
    *destinationReg = value;
}

void executeOpcode(
    uint8_t opcode, 
    cpu_t* cpu, 
    mem_t* mem)
{
    if (opcode == 0xCB)
    {
        opcode = fetchEightBitMem(mem, readAndAdvancePC(cpu));
        cbOpcodes[opcode](cpu, mem);
    }
    else
    {
        normalOpcodes[opcode](cpu, mem);
    }
}

uint16_t readAndAdvancePC(
    cpu_t* cpu)
{
    return cpu->reg_PC++;
}

uint16_t extendRegisterToMemValue(
    uint8_t reg)
{
    return 0xFF00 + reg;
}

flag_value_t getFlag(
    cpu_t* cpu, 
    flags_t flag)
{
    if (cpu->reg_F & flag)
       return FLAG_SET;
    return FLAG_NOT_SET;
}


void setFlag(
    cpu_t* cpu, 
    flags_t flag, 
    flag_value_t value)
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

void printFlags(
    cpu_t* cpu)
{
    printf("Z: %u\t",getFlag(cpu, flag_Z));
    printf("N: %u\t",getFlag(cpu, flag_N));
    printf("H: %u\t",getFlag(cpu, flag_H));
    printf("C: %u\n",getFlag(cpu, flag_C));
}
void printRegs(
    cpu_t* cpu)
{
    printf("A: %02x\t",cpu->reg_A);
    printf("F: %02x\t",cpu->reg_F);
    printf("B: %02x\t",cpu->reg_B);
    printf("C: %02x\t",cpu->reg_C);
    printf("D: %02x\t",cpu->reg_D);
    printf("E: %02x\t",cpu->reg_E);
    printf("H: %02x\t",cpu->reg_H);
    printf("L: %02x\n",cpu->reg_L);
}