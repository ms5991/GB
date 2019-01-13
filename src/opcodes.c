#include <stdlib.h>
#include "opcodes.h"
#include "cpu.h"

// unused func as placeholder
void unusedFunc(cpu_t* cpu, mem_t* mem){}


// ================= NON-PREFIXED =============================
// cycles=4,addr=0x0,length=1
// flags:Z=-,N=-,H=-,C=-
void NOP(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x1,length=3
// flags:Z=-,N=-,H=-,C=-
void LD_BC_d16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_BC_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3,length=1
// flags:Z=-,N=-,H=-,C=-
void INC_BC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_B, cpu->reg_B, 1, ALU_INC);
}

// cycles=4,addr=0x5,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_B, cpu->reg_B, 1, ALU_DEC);
}

// cycles=8,addr=0x6,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_B_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7,length=1
// flags:Z=0,N=0,H=0,C=C
void RLCA(cpu_t* cpu, mem_t* mem)
{
}

// cycles=20,addr=0x8,length=3
// flags:Z=-,N=-,H=-,C=-
void LD__OP_a16_CP__SP(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9,length=1
// flags:Z=-,N=0,H=H,C=C
void ADD_HL_BC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_BC_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb,length=1
// flags:Z=-,N=-,H=-,C=-
void DEC_BC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xc,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_C, cpu->reg_C, 1, ALU_INC);
}

// cycles=4,addr=0xd,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_B, cpu->reg_B, 1, ALU_DEC);
}

// cycles=8,addr=0xe,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_C_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xf,length=1
// flags:Z=0,N=0,H=0,C=C
void RRCA(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x10,length=2
// flags:Z=-,N=-,H=-,C=-
void STOP_0(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x11,length=3
// flags:Z=-,N=-,H=-,C=-
void LD_DE_d16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x12,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_DE_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x13,length=1
// flags:Z=-,N=-,H=-,C=-
void INC_DE(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x14,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_D, cpu->reg_D, 1, ALU_INC);
}

// cycles=4,addr=0x15,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_D, cpu->reg_D, 1, ALU_DEC);
}

// cycles=8,addr=0x16,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_D_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x17,length=1
// flags:Z=0,N=0,H=0,C=C
void RLA(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x18,length=2
// flags:Z=-,N=-,H=-,C=-
void JR_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x19,length=1
// flags:Z=-,N=0,H=H,C=C
void ADD_HL_DE(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_DE_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1b,length=1
// flags:Z=-,N=-,H=-,C=-
void DEC_DE(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x1c,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_E, cpu->reg_E, 1, ALU_INC);
}

// cycles=4,addr=0x1d,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_E, cpu->reg_E, 1, ALU_DEC);
}

// cycles=8,addr=0x1e,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_E_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x1f,length=1
// flags:Z=0,N=0,H=0,C=C
void RRA(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x20,length=2
// flags:Z=-,N=-,H=-,C=-
void JR_NZ_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x21,length=3
// flags:Z=-,N=-,H=-,C=-
void LD_HL_d16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x22,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_PLUS__CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x23,length=1
// flags:Z=-,N=-,H=-,C=-
void INC_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x24,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_H, cpu->reg_H, 1, ALU_INC);
}

// cycles=4,addr=0x25,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_H, cpu->reg_H, 1, ALU_DEC);
}

// cycles=8,addr=0x26,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_H_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x27,length=1
// flags:Z=Z,N=-,H=0,C=C
void DAA(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x28,length=2
// flags:Z=-,N=-,H=-,C=-
void JR_Z_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x29,length=1
// flags:Z=-,N=0,H=H,C=C
void ADD_HL_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_HL_PLUS__CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2b,length=1
// flags:Z=-,N=-,H=-,C=-
void DEC_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x2c,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_L, cpu->reg_L, 1, ALU_INC);
}

// cycles=4,addr=0x2d,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_L, cpu->reg_L, 1, ALU_DEC);
}

// cycles=8,addr=0x2e,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_L_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x2f,length=1
// flags:Z=-,N=1,H=1,C=-
void CPL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x30,length=2
// flags:Z=-,N=-,H=-,C=-
void JR_NC_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x31,length=3
// flags:Z=-,N=-,H=-,C=-
void LD_SP_d16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x32,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_MINUS__CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x33,length=1
// flags:Z=-,N=-,H=-,C=-
void INC_SP(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x34,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x35,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x36,length=2
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x37,length=1
// flags:Z=-,N=0,H=0,C=1
void SCF(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0x38,length=2
// flags:Z=-,N=-,H=-,C=-
void JR_C_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x39,length=1
// flags:Z=-,N=0,H=H,C=C
void ADD_HL_SP(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_HL_MINUS__CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3b,length=1
// flags:Z=-,N=-,H=-,C=-
void DEC_SP(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x3c,length=1
// flags:Z=Z,N=0,H=H,C=-
void INC_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, 1, ALU_INC);
}

// cycles=4,addr=0x3d,length=1
// flags:Z=Z,N=1,H=H,C=-
void DEC_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, 1, ALU_DEC);
}

// cycles=8,addr=0x3e,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_A_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x3f,length=1
// flags:Z=-,N=0,H=0,C=C
void CCF(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x40,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x41,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x42,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x43,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x44,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x45,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x46,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x47,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_B_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x48,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x49,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4b,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4c,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4d,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4e,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x4f,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_C_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x50,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x51,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x52,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x53,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x54,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x55,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x56,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x57,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_D_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x58,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x59,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x5a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x5b,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x5c,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x5d,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5e,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x5f,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_E_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x60,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x61,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x62,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x63,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x64,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x65,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x66,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x67,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_H_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x68,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x69,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x6a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x6b,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x6c,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x6d,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6e,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x6f,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_L_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x70,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x71,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x72,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x73,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x74,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x75,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x76,length=1
// flags:Z=-,N=-,H=-,C=-
void HALT(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x77,length=1
// flags:Z=-,N=-,H=-,C=-
void LD__OP_HL_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x78,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x79,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7a,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7b,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7c,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7d,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7e,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x7f,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_A_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x80,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_ADD);
}

// cycles=4,addr=0x81,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_ADD);
}

// cycles=4,addr=0x82,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_ADD);
}

// cycles=4,addr=0x83,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_ADD);
}

// cycles=4,addr=0x84,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_ADD);
}

// cycles=4,addr=0x85,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_ADD);
}

// cycles=8,addr=0x86,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x87,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_ADD);
}

// cycles=4,addr=0x88,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_ADC);
}

// cycles=4,addr=0x89,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_ADC);
}

// cycles=4,addr=0x8a,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_ADC);
}

// cycles=4,addr=0x8b,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_ADC);
}

// cycles=4,addr=0x8c,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_ADC);
}

// cycles=4,addr=0x8d,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_ADC);
}

// cycles=8,addr=0x8e,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x8f,length=1
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_ADC);
}

// cycles=4,addr=0x90,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_SUB);
}

// cycles=4,addr=0x91,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_SUB);
}

// cycles=4,addr=0x92,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_SUB);
}

// cycles=4,addr=0x93,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_SUB);
}

// cycles=4,addr=0x94,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_SUB);
}

// cycles=4,addr=0x95,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_SUB);
}

// cycles=8,addr=0x96,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x97,length=1
// flags:Z=Z,N=1,H=H,C=C
void SUB_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_SUB);
}

// cycles=4,addr=0x98,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x99,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x9a,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x9b,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x9c,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x9d,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9e,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0x9f,length=1
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xa0,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_AND);
}

// cycles=4,addr=0xa1,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_AND);
}

// cycles=4,addr=0xa2,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_AND);
}

// cycles=4,addr=0xa3,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_AND);
}

// cycles=4,addr=0xa4,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_AND);
}

// cycles=4,addr=0xa5,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_AND);
}

// cycles=8,addr=0xa6,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xa7,length=1
// flags:Z=Z,N=0,H=1,C=0
void AND_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_AND);
}

// cycles=4,addr=0xa8,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_XOR);
}

// cycles=4,addr=0xa9,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_XOR);
}

// cycles=4,addr=0xaa,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_XOR);
}

// cycles=4,addr=0xab,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_XOR);
}

// cycles=4,addr=0xac,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_XOR);
}

// cycles=4,addr=0xad,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_XOR);
}

// cycles=8,addr=0xae,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xaf,length=1
// flags:Z=Z,N=0,H=0,C=0
void XOR_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_XOR);
}

// cycles=4,addr=0xb0,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_B(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_B, ALU_OR);
}

// cycles=4,addr=0xb1,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_C(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_C, ALU_OR);
}

// cycles=4,addr=0xb2,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_D(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_D, ALU_OR);
}

// cycles=4,addr=0xb3,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_E(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_E, ALU_OR);
}

// cycles=4,addr=0xb4,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_H(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_H, ALU_OR);
}

// cycles=4,addr=0xb5,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_L(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_L, ALU_OR);
}

// cycles=8,addr=0xb6,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xb7,length=1
// flags:Z=Z,N=0,H=0,C=0
void OR_A(cpu_t* cpu, mem_t* mem)
{
    executeEightBitALUOp(cpu, &cpu->reg_A, cpu->reg_A, cpu->reg_A, ALU_OR);
}

// cycles=4,addr=0xb8,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xb9,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xba,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xbb,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xbc,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xbd,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xbe,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xbf,length=1
// flags:Z=Z,N=1,H=H,C=C
void CP_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=20,addr=0xc0,length=1
// flags:Z=-,N=-,H=-,C=-
void RET_NZ(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xc1,length=1
// flags:Z=-,N=-,H=-,C=-
void POP_BC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc2,length=3
// flags:Z=-,N=-,H=-,C=-
void JP_NZ_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc3,length=3
// flags:Z=-,N=-,H=-,C=-
void JP_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=24,addr=0xc4,length=3
// flags:Z=-,N=-,H=-,C=-
void CALL_NZ_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc5,length=1
// flags:Z=-,N=-,H=-,C=-
void PUSH_BC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc6,length=2
// flags:Z=Z,N=0,H=H,C=C
void ADD_A_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc7,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_00H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=20,addr=0xc8,length=1
// flags:Z=-,N=-,H=-,C=-
void RET_Z(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc9,length=1
// flags:Z=-,N=-,H=-,C=-
void RET(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xca,length=3
// flags:Z=-,N=-,H=-,C=-
void JP_Z_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xcb,length=1
// flags:Z=-,N=-,H=-,C=-
void PREFIX_CB(cpu_t* cpu, mem_t* mem)
{
}

// cycles=24,addr=0xcc,length=3
// flags:Z=-,N=-,H=-,C=-
void CALL_Z_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=24,addr=0xcd,length=3
// flags:Z=-,N=-,H=-,C=-
void CALL_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xce,length=2
// flags:Z=Z,N=0,H=H,C=C
void ADC_A_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xcf,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_08H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=20,addr=0xd0,length=1
// flags:Z=-,N=-,H=-,C=-
void RET_NC(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xd1,length=1
// flags:Z=-,N=-,H=-,C=-
void POP_DE(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xd2,length=3
// flags:Z=-,N=-,H=-,C=-
void JP_NC_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=24,addr=0xd4,length=3
// flags:Z=-,N=-,H=-,C=-
void CALL_NC_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xd5,length=1
// flags:Z=-,N=-,H=-,C=-
void PUSH_DE(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd6,length=2
// flags:Z=Z,N=1,H=H,C=C
void SUB_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xd7,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_10H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=20,addr=0xd8,length=1
// flags:Z=-,N=-,H=-,C=-
void RET_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xd9,length=1
// flags:Z=-,N=-,H=-,C=-
void RETI(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xda,length=3
// flags:Z=-,N=-,H=-,C=-
void JP_C_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=24,addr=0xdc,length=3
// flags:Z=-,N=-,H=-,C=-
void CALL_C_a16(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xde,length=2
// flags:Z=Z,N=1,H=H,C=C
void SBC_A_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xdf,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_18H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xe0,length=2
// flags:Z=-,N=-,H=-,C=-
void LDH__OP_a8_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xe1,length=1
// flags:Z=-,N=-,H=-,C=-
void POP_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe2,length=2
// flags:Z=-,N=-,H=-,C=-
void LD__OP_C_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xe5,length=1
// flags:Z=-,N=-,H=-,C=-
void PUSH_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe6,length=2
// flags:Z=Z,N=0,H=1,C=0
void AND_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xe7,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_20H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xe8,length=2
// flags:Z=0,N=0,H=H,C=C
void ADD_SP_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xe9,length=1
// flags:Z=-,N=-,H=-,C=-
void JP__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xea,length=3
// flags:Z=-,N=-,H=-,C=-
void LD__OP_a16_CP__A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xee,length=2
// flags:Z=Z,N=0,H=0,C=0
void XOR_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xef,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_28H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xf0,length=2
// flags:Z=-,N=-,H=-,C=-
void LDH_A__OP_a8_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xf1,length=1
// flags:Z=Z,N=N,H=H,C=C
void POP_AF(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf2,length=2
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_C_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xf3,length=1
// flags:Z=-,N=-,H=-,C=-
void DI(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xf5,length=1
// flags:Z=-,N=-,H=-,C=-
void PUSH_AF(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf6,length=2
// flags:Z=Z,N=0,H=0,C=0
void OR_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xf7,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_30H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=12,addr=0xf8,length=2
// flags:Z=0,N=0,H=H,C=C
void LD_HL_SP_PLUS_r8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf9,length=1
// flags:Z=-,N=-,H=-,C=-
void LD_SP_HL(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xfa,length=3
// flags:Z=-,N=-,H=-,C=-
void LD_A__OP_a16_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=4,addr=0xfb,length=1
// flags:Z=-,N=-,H=-,C=-
void EI(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xfe,length=2
// flags:Z=Z,N=1,H=H,C=C
void CP_d8(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xff,length=1
// flags:Z=-,N=-,H=-,C=-
void RST_38H(cpu_t* cpu, mem_t* mem)
{
}

// ================== CB-PREFIXED =============================
// cycles=8,addr=0x0,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x6,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RLC_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xe,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RRC_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x10,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x11,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x12,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x13,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x14,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x15,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x16,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x17,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RL_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x18,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x19,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1a,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1b,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1c,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1d,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x1e,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x1f,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_RR_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x20,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x21,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x22,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x23,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x24,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x25,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x26,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x27,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SLA_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x28,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x29,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2a,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2b,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2c,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2d,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x2e,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x2f,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SRA_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x30,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x31,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x32,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x33,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x34,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x35,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x36,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x37,length=2
// flags:Z=Z,N=0,H=0,C=0
void cb_SWAP_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x38,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x39,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3a,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3b,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3c,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3d,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x3e,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x3f,length=2
// flags:Z=Z,N=0,H=0,C=C
void cb_SRL_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x40,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x41,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x42,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x43,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x44,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x45,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x46,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x47,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_0_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x48,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x49,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4a,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4b,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4c,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4d,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x4e,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x4f,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_1_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x50,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x51,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x52,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x53,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x54,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x55,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x56,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x57,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_2_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x58,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x59,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5a,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5b,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5c,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5d,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x5e,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x5f,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_3_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x60,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x61,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x62,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x63,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x64,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x65,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x66,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x67,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_4_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x68,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x69,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6a,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6b,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6c,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6d,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x6e,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x6f,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_5_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x70,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x71,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x72,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x73,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x74,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x75,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x76,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x77,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_6_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x78,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x79,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7a,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7b,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7c,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7d,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x7e,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x7f,length=2
// flags:Z=Z,N=0,H=1,C=-
void cb_BIT_7_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x80,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x81,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x82,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x83,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x84,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x85,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x86,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x87,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_0_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x88,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x89,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8a,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8b,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8c,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8d,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x8e,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x8f,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_1_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x90,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x91,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x92,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x93,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x94,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x95,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x96,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x97,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_2_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x98,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x99,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9a,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9b,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9c,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9d,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0x9e,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0x9f,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_3_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xa6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_4_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xa9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xaa,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xab,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xac,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xad,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xae,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xaf,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_5_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xb6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_6_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xb9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xba,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xbb,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xbc,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xbd,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xbe,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xbf,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_RES_7_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xc6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_0_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xc9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xca,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xcb,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xcc,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xcd,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xce,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xcf,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_1_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xd6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_2_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xd9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xda,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xdb,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xdc,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xdd,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xde,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xdf,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_3_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xe6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_4_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xe9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xea,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xeb,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xec,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xed,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xee,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xef,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_5_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf0,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf1,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf2,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf3,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf4,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf5,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xf6,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf7,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_6_A(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf8,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_B(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xf9,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_C(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xfa,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_D(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xfb,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_E(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xfc,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_H(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xfd,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_L(cpu_t* cpu, mem_t* mem)
{
}

// cycles=16,addr=0xfe,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem)
{
}

// cycles=8,addr=0xff,length=2
// flags:Z=-,N=-,H=-,C=-
void cb_SET_7_A(cpu_t* cpu, mem_t* mem)
{
}