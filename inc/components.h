#ifndef _COMP_H
#define _COMP_H

#include <stdint.h>

#define RAM_SIZE 65536

typedef struct
{
    uint16_t reg_PC;
    uint16_t reg_SP;
    uint8_t reg_A;
    uint8_t reg_F;
    uint8_t reg_B;
    uint8_t reg_C;
    uint8_t reg_D;
    uint8_t reg_E;
    uint8_t reg_H;
    uint8_t reg_L;
} cpu_t;

typedef enum
{
    ALU_ADD,
    ALU_SUB,
    ALU_AND,
    ALU_OR,
    ALU_XOR,
    ALU_INC,
    ALU_DEC,
    ALU_ADC,
    ALU_SBC
} alu_op_t;

typedef uint8_t (*result_flag_calc_t)(
    cpu_t* cpu,
    uint8_t result,
    uint8_t op1,
    uint8_t op2,
    alu_op_t aluOp);

typedef enum
{
    FLAG_SET,
    FLAG_NOT_SET
} flag_value_t;


typedef enum
{
    OP_FLAG_SET_OFF,
    OP_FLAG_SET_ON,
    OP_FLAG_TOGGLE,
    OP_FLAG_PER_RESULT,
    OP_FLAG_NO_OP
} flag_operation_t;

typedef enum 
{
    flag_Z = 1 << 7, // zero
    flag_N = 1 << 6, // subtraction
    flag_H = 1 << 5, // half carry
    flag_C = 1 << 4  // carry
} flags_t;

typedef struct 
{
    uint8_t ram [RAM_SIZE];
} mem_t;

typedef void (*opcode_t)(
    cpu_t* cpu,
    mem_t* mem);


#endif
