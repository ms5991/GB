#ifndef _COMP_H
#define _COMP_H

#include <stdint.h>

#define RAM_SIZE 65536

typedef enum
{
    NOT_SET = 0,
    SET = 1
} flagValue_t;

typedef enum 
{
    flag_Z = 1 << 7,
    flag_N = 1 << 6,
    flag_H = 1 << 5,
    flag_C = 1 << 4
} flags_t;


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

typedef struct 
{
    uint8_t ram [RAM_SIZE];
} mem_t;

typedef void (*opcode_t)(cpu_t* cpu, mem_t* mem);


#endif
