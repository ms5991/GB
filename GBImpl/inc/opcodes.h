#ifndef _OPCODES_H
#define _OPCODES_H


#include "components.h"
#define NUM_NORMAL_OPCODES 256
#define NUM_CB_OPCODES 256
// unused func as placeholder
void unusedFunc(cpu_t* cpu, mem_t* mem);

// ================= NON-PREFIXED =============================
// cycles=4,addr=0x0,length=1
void NOP(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x1,length=3
void LD_BC_d16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2,length=1
void LD__OP_BC_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3,length=1
void INC_BC(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4,length=1
void INC_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5,length=1
void DEC_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6,length=2
void LD_B_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7,length=1
void RLCA(cpu_t* cpu, mem_t* mem);

// cycles=20,addr=0x8,length=3
void LD__OP_a16_CP__SP(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9,length=1
void ADD_HL_BC(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa,length=1
void LD_A__OP_BC_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb,length=1
void DEC_BC(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xc,length=1
void INC_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xd,length=1
void DEC_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe,length=2
void LD_C_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xf,length=1
void RRCA(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x10,length=2
void STOP_0(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x11,length=3
void LD_DE_d16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x12,length=1
void LD__OP_DE_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x13,length=1
void INC_DE(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x14,length=1
void INC_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x15,length=1
void DEC_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x16,length=2
void LD_D_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x17,length=1
void RLA(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x18,length=2
void JR_r8(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x19,length=1
void ADD_HL_DE(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1a,length=1
void LD_A__OP_DE_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1b,length=1
void DEC_DE(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x1c,length=1
void INC_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x1d,length=1
void DEC_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1e,length=2
void LD_E_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x1f,length=1
void RRA(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x20,length=2
void JR_NZ_r8(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x21,length=3
void LD_HL_d16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x22,length=1
void LD__OP_HL_PLUS__CP__A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x23,length=1
void INC_HL(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x24,length=1
void INC_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x25,length=1
void DEC_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x26,length=2
void LD_H_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x27,length=1
void DAA(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x28,length=2
void JR_Z_r8(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x29,length=1
void ADD_HL_HL(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2a,length=1
void LD_A__OP_HL_PLUS__CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2b,length=1
void DEC_HL(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x2c,length=1
void INC_L(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x2d,length=1
void DEC_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2e,length=2
void LD_L_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x2f,length=1
void CPL(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x30,length=2
void JR_NC_r8(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x31,length=3
void LD_SP_d16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x32,length=1
void LD__OP_HL_MINUS__CP__A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x33,length=1
void INC_SP(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x34,length=1
void INC__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x35,length=1
void DEC__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x36,length=2
void LD__OP_HL_CP__d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x37,length=1
void SCF(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0x38,length=2
void JR_C_r8(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x39,length=1
void ADD_HL_SP(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3a,length=1
void LD_A__OP_HL_MINUS__CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3b,length=1
void DEC_SP(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x3c,length=1
void INC_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x3d,length=1
void DEC_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3e,length=2
void LD_A_d8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x3f,length=1
void CCF(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x40,length=1
void LD_B_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x41,length=1
void LD_B_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x42,length=1
void LD_B_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x43,length=1
void LD_B_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x44,length=1
void LD_B_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x45,length=1
void LD_B_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x46,length=1
void LD_B__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x47,length=1
void LD_B_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x48,length=1
void LD_C_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x49,length=1
void LD_C_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4a,length=1
void LD_C_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4b,length=1
void LD_C_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4c,length=1
void LD_C_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4d,length=1
void LD_C_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4e,length=1
void LD_C__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x4f,length=1
void LD_C_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x50,length=1
void LD_D_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x51,length=1
void LD_D_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x52,length=1
void LD_D_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x53,length=1
void LD_D_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x54,length=1
void LD_D_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x55,length=1
void LD_D_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x56,length=1
void LD_D__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x57,length=1
void LD_D_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x58,length=1
void LD_E_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x59,length=1
void LD_E_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5a,length=1
void LD_E_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5b,length=1
void LD_E_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5c,length=1
void LD_E_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5d,length=1
void LD_E_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5e,length=1
void LD_E__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x5f,length=1
void LD_E_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x60,length=1
void LD_H_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x61,length=1
void LD_H_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x62,length=1
void LD_H_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x63,length=1
void LD_H_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x64,length=1
void LD_H_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x65,length=1
void LD_H_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x66,length=1
void LD_H__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x67,length=1
void LD_H_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x68,length=1
void LD_L_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x69,length=1
void LD_L_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x6a,length=1
void LD_L_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x6b,length=1
void LD_L_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x6c,length=1
void LD_L_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x6d,length=1
void LD_L_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6e,length=1
void LD_L__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x6f,length=1
void LD_L_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x70,length=1
void LD__OP_HL_CP__B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x71,length=1
void LD__OP_HL_CP__C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x72,length=1
void LD__OP_HL_CP__D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x73,length=1
void LD__OP_HL_CP__E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x74,length=1
void LD__OP_HL_CP__H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x75,length=1
void LD__OP_HL_CP__L(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x76,length=1
void HALT(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x77,length=1
void LD__OP_HL_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x78,length=1
void LD_A_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x79,length=1
void LD_A_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7a,length=1
void LD_A_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7b,length=1
void LD_A_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7c,length=1
void LD_A_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7d,length=1
void LD_A_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7e,length=1
void LD_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x7f,length=1
void LD_A_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x80,length=1
void ADD_A_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x81,length=1
void ADD_A_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x82,length=1
void ADD_A_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x83,length=1
void ADD_A_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x84,length=1
void ADD_A_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x85,length=1
void ADD_A_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x86,length=1
void ADD_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x87,length=1
void ADD_A_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x88,length=1
void ADC_A_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x89,length=1
void ADC_A_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x8a,length=1
void ADC_A_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x8b,length=1
void ADC_A_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x8c,length=1
void ADC_A_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x8d,length=1
void ADC_A_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8e,length=1
void ADC_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x8f,length=1
void ADC_A_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x90,length=1
void SUB_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x91,length=1
void SUB_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x92,length=1
void SUB_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x93,length=1
void SUB_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x94,length=1
void SUB_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x95,length=1
void SUB_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x96,length=1
void SUB__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x97,length=1
void SUB_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x98,length=1
void SBC_A_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x99,length=1
void SBC_A_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x9a,length=1
void SBC_A_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x9b,length=1
void SBC_A_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x9c,length=1
void SBC_A_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x9d,length=1
void SBC_A_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9e,length=1
void SBC_A__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0x9f,length=1
void SBC_A_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa0,length=1
void AND_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa1,length=1
void AND_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa2,length=1
void AND_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa3,length=1
void AND_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa4,length=1
void AND_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa5,length=1
void AND_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa6,length=1
void AND__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa7,length=1
void AND_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa8,length=1
void XOR_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xa9,length=1
void XOR_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xaa,length=1
void XOR_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xab,length=1
void XOR_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xac,length=1
void XOR_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xad,length=1
void XOR_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xae,length=1
void XOR__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xaf,length=1
void XOR_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb0,length=1
void OR_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb1,length=1
void OR_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb2,length=1
void OR_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb3,length=1
void OR_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb4,length=1
void OR_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb5,length=1
void OR_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb6,length=1
void OR__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb7,length=1
void OR_A(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb8,length=1
void CP_B(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xb9,length=1
void CP_C(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xba,length=1
void CP_D(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xbb,length=1
void CP_E(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xbc,length=1
void CP_H(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xbd,length=1
void CP_L(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xbe,length=1
void CP__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xbf,length=1
void CP_A(cpu_t* cpu, mem_t* mem);

// cycles=20,addr=0xc0,length=1
void RET_NZ(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xc1,length=1
void POP_BC(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc2,length=3
void JP_NZ_a16(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc3,length=3
void JP_a16(cpu_t* cpu, mem_t* mem);

// cycles=24,addr=0xc4,length=3
void CALL_NZ_a16(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc5,length=1
void PUSH_BC(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc6,length=2
void ADD_A_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc7,length=1
void RST_00H(cpu_t* cpu, mem_t* mem);

// cycles=20,addr=0xc8,length=1
void RET_Z(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc9,length=1
void RET(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xca,length=3
void JP_Z_a16(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xcb,length=1
void PREFIX_CB(cpu_t* cpu, mem_t* mem);

// cycles=24,addr=0xcc,length=3
void CALL_Z_a16(cpu_t* cpu, mem_t* mem);

// cycles=24,addr=0xcd,length=3
void CALL_a16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xce,length=2
void ADC_A_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xcf,length=1
void RST_08H(cpu_t* cpu, mem_t* mem);

// cycles=20,addr=0xd0,length=1
void RET_NC(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xd1,length=1
void POP_DE(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xd2,length=3
void JP_NC_a16(cpu_t* cpu, mem_t* mem);

// cycles=24,addr=0xd4,length=3
void CALL_NC_a16(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xd5,length=1
void PUSH_DE(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd6,length=2
void SUB_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xd7,length=1
void RST_10H(cpu_t* cpu, mem_t* mem);

// cycles=20,addr=0xd8,length=1
void RET_C(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xd9,length=1
void RETI(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xda,length=3
void JP_C_a16(cpu_t* cpu, mem_t* mem);

// cycles=24,addr=0xdc,length=3
void CALL_C_a16(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xde,length=2
void SBC_A_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xdf,length=1
void RST_18H(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xe0,length=2
void LDH__OP_a8_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xe1,length=1
void POP_HL(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe2,length=2
void LD__OP_C_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xe5,length=1
void PUSH_HL(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe6,length=2
void AND_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xe7,length=1
void RST_20H(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xe8,length=2
void ADD_SP_r8(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xe9,length=1
void JP__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xea,length=3
void LD__OP_a16_CP__A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xee,length=2
void XOR_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xef,length=1
void RST_28H(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xf0,length=2
void LDH_A__OP_a8_CP_(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xf1,length=1
void POP_AF(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf2,length=2
void LD_A__OP_C_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xf3,length=1
void DI(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xf5,length=1
void PUSH_AF(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf6,length=2
void OR_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xf7,length=1
void RST_30H(cpu_t* cpu, mem_t* mem);

// cycles=12,addr=0xf8,length=2
void LD_HL_SP_PLUS_r8(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf9,length=1
void LD_SP_HL(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xfa,length=3
void LD_A__OP_a16_CP_(cpu_t* cpu, mem_t* mem);

// cycles=4,addr=0xfb,length=1
void EI(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xfe,length=2
void CP_d8(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xff,length=1
void RST_38H(cpu_t* cpu, mem_t* mem);

// ================== CB-PREFIXED =============================
// cycles=8,addr=0x0,length=2
void cb_RLC_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1,length=2
void cb_RLC_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2,length=2
void cb_RLC_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3,length=2
void cb_RLC_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4,length=2
void cb_RLC_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5,length=2
void cb_RLC_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x6,length=2
void cb_RLC__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7,length=2
void cb_RLC_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8,length=2
void cb_RRC_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9,length=2
void cb_RRC_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa,length=2
void cb_RRC_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb,length=2
void cb_RRC_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc,length=2
void cb_RRC_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd,length=2
void cb_RRC_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xe,length=2
void cb_RRC__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf,length=2
void cb_RRC_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x10,length=2
void cb_RL_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x11,length=2
void cb_RL_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x12,length=2
void cb_RL_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x13,length=2
void cb_RL_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x14,length=2
void cb_RL_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x15,length=2
void cb_RL_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x16,length=2
void cb_RL__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x17,length=2
void cb_RL_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x18,length=2
void cb_RR_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x19,length=2
void cb_RR_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1a,length=2
void cb_RR_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1b,length=2
void cb_RR_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1c,length=2
void cb_RR_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1d,length=2
void cb_RR_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x1e,length=2
void cb_RR__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x1f,length=2
void cb_RR_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x20,length=2
void cb_SLA_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x21,length=2
void cb_SLA_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x22,length=2
void cb_SLA_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x23,length=2
void cb_SLA_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x24,length=2
void cb_SLA_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x25,length=2
void cb_SLA_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x26,length=2
void cb_SLA__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x27,length=2
void cb_SLA_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x28,length=2
void cb_SRA_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x29,length=2
void cb_SRA_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2a,length=2
void cb_SRA_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2b,length=2
void cb_SRA_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2c,length=2
void cb_SRA_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2d,length=2
void cb_SRA_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x2e,length=2
void cb_SRA__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x2f,length=2
void cb_SRA_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x30,length=2
void cb_SWAP_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x31,length=2
void cb_SWAP_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x32,length=2
void cb_SWAP_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x33,length=2
void cb_SWAP_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x34,length=2
void cb_SWAP_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x35,length=2
void cb_SWAP_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x36,length=2
void cb_SWAP__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x37,length=2
void cb_SWAP_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x38,length=2
void cb_SRL_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x39,length=2
void cb_SRL_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3a,length=2
void cb_SRL_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3b,length=2
void cb_SRL_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3c,length=2
void cb_SRL_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3d,length=2
void cb_SRL_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x3e,length=2
void cb_SRL__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x3f,length=2
void cb_SRL_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x40,length=2
void cb_BIT_0_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x41,length=2
void cb_BIT_0_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x42,length=2
void cb_BIT_0_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x43,length=2
void cb_BIT_0_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x44,length=2
void cb_BIT_0_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x45,length=2
void cb_BIT_0_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x46,length=2
void cb_BIT_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x47,length=2
void cb_BIT_0_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x48,length=2
void cb_BIT_1_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x49,length=2
void cb_BIT_1_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4a,length=2
void cb_BIT_1_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4b,length=2
void cb_BIT_1_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4c,length=2
void cb_BIT_1_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4d,length=2
void cb_BIT_1_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x4e,length=2
void cb_BIT_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x4f,length=2
void cb_BIT_1_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x50,length=2
void cb_BIT_2_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x51,length=2
void cb_BIT_2_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x52,length=2
void cb_BIT_2_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x53,length=2
void cb_BIT_2_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x54,length=2
void cb_BIT_2_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x55,length=2
void cb_BIT_2_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x56,length=2
void cb_BIT_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x57,length=2
void cb_BIT_2_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x58,length=2
void cb_BIT_3_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x59,length=2
void cb_BIT_3_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5a,length=2
void cb_BIT_3_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5b,length=2
void cb_BIT_3_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5c,length=2
void cb_BIT_3_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5d,length=2
void cb_BIT_3_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x5e,length=2
void cb_BIT_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x5f,length=2
void cb_BIT_3_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x60,length=2
void cb_BIT_4_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x61,length=2
void cb_BIT_4_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x62,length=2
void cb_BIT_4_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x63,length=2
void cb_BIT_4_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x64,length=2
void cb_BIT_4_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x65,length=2
void cb_BIT_4_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x66,length=2
void cb_BIT_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x67,length=2
void cb_BIT_4_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x68,length=2
void cb_BIT_5_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x69,length=2
void cb_BIT_5_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6a,length=2
void cb_BIT_5_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6b,length=2
void cb_BIT_5_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6c,length=2
void cb_BIT_5_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6d,length=2
void cb_BIT_5_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x6e,length=2
void cb_BIT_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x6f,length=2
void cb_BIT_5_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x70,length=2
void cb_BIT_6_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x71,length=2
void cb_BIT_6_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x72,length=2
void cb_BIT_6_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x73,length=2
void cb_BIT_6_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x74,length=2
void cb_BIT_6_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x75,length=2
void cb_BIT_6_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x76,length=2
void cb_BIT_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x77,length=2
void cb_BIT_6_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x78,length=2
void cb_BIT_7_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x79,length=2
void cb_BIT_7_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7a,length=2
void cb_BIT_7_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7b,length=2
void cb_BIT_7_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7c,length=2
void cb_BIT_7_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7d,length=2
void cb_BIT_7_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x7e,length=2
void cb_BIT_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x7f,length=2
void cb_BIT_7_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x80,length=2
void cb_RES_0_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x81,length=2
void cb_RES_0_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x82,length=2
void cb_RES_0_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x83,length=2
void cb_RES_0_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x84,length=2
void cb_RES_0_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x85,length=2
void cb_RES_0_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x86,length=2
void cb_RES_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x87,length=2
void cb_RES_0_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x88,length=2
void cb_RES_1_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x89,length=2
void cb_RES_1_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8a,length=2
void cb_RES_1_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8b,length=2
void cb_RES_1_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8c,length=2
void cb_RES_1_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8d,length=2
void cb_RES_1_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x8e,length=2
void cb_RES_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x8f,length=2
void cb_RES_1_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x90,length=2
void cb_RES_2_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x91,length=2
void cb_RES_2_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x92,length=2
void cb_RES_2_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x93,length=2
void cb_RES_2_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x94,length=2
void cb_RES_2_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x95,length=2
void cb_RES_2_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x96,length=2
void cb_RES_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x97,length=2
void cb_RES_2_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x98,length=2
void cb_RES_3_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x99,length=2
void cb_RES_3_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9a,length=2
void cb_RES_3_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9b,length=2
void cb_RES_3_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9c,length=2
void cb_RES_3_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9d,length=2
void cb_RES_3_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0x9e,length=2
void cb_RES_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0x9f,length=2
void cb_RES_3_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa0,length=2
void cb_RES_4_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa1,length=2
void cb_RES_4_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa2,length=2
void cb_RES_4_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa3,length=2
void cb_RES_4_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa4,length=2
void cb_RES_4_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa5,length=2
void cb_RES_4_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xa6,length=2
void cb_RES_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa7,length=2
void cb_RES_4_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa8,length=2
void cb_RES_5_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xa9,length=2
void cb_RES_5_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xaa,length=2
void cb_RES_5_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xab,length=2
void cb_RES_5_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xac,length=2
void cb_RES_5_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xad,length=2
void cb_RES_5_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xae,length=2
void cb_RES_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xaf,length=2
void cb_RES_5_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb0,length=2
void cb_RES_6_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb1,length=2
void cb_RES_6_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb2,length=2
void cb_RES_6_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb3,length=2
void cb_RES_6_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb4,length=2
void cb_RES_6_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb5,length=2
void cb_RES_6_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xb6,length=2
void cb_RES_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb7,length=2
void cb_RES_6_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb8,length=2
void cb_RES_7_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xb9,length=2
void cb_RES_7_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xba,length=2
void cb_RES_7_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xbb,length=2
void cb_RES_7_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xbc,length=2
void cb_RES_7_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xbd,length=2
void cb_RES_7_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xbe,length=2
void cb_RES_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xbf,length=2
void cb_RES_7_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc0,length=2
void cb_SET_0_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc1,length=2
void cb_SET_0_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc2,length=2
void cb_SET_0_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc3,length=2
void cb_SET_0_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc4,length=2
void cb_SET_0_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc5,length=2
void cb_SET_0_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xc6,length=2
void cb_SET_0__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc7,length=2
void cb_SET_0_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc8,length=2
void cb_SET_1_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xc9,length=2
void cb_SET_1_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xca,length=2
void cb_SET_1_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xcb,length=2
void cb_SET_1_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xcc,length=2
void cb_SET_1_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xcd,length=2
void cb_SET_1_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xce,length=2
void cb_SET_1__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xcf,length=2
void cb_SET_1_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd0,length=2
void cb_SET_2_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd1,length=2
void cb_SET_2_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd2,length=2
void cb_SET_2_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd3,length=2
void cb_SET_2_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd4,length=2
void cb_SET_2_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd5,length=2
void cb_SET_2_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xd6,length=2
void cb_SET_2__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd7,length=2
void cb_SET_2_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd8,length=2
void cb_SET_3_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xd9,length=2
void cb_SET_3_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xda,length=2
void cb_SET_3_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xdb,length=2
void cb_SET_3_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xdc,length=2
void cb_SET_3_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xdd,length=2
void cb_SET_3_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xde,length=2
void cb_SET_3__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xdf,length=2
void cb_SET_3_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe0,length=2
void cb_SET_4_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe1,length=2
void cb_SET_4_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe2,length=2
void cb_SET_4_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe3,length=2
void cb_SET_4_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe4,length=2
void cb_SET_4_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe5,length=2
void cb_SET_4_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xe6,length=2
void cb_SET_4__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe7,length=2
void cb_SET_4_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe8,length=2
void cb_SET_5_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xe9,length=2
void cb_SET_5_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xea,length=2
void cb_SET_5_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xeb,length=2
void cb_SET_5_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xec,length=2
void cb_SET_5_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xed,length=2
void cb_SET_5_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xee,length=2
void cb_SET_5__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xef,length=2
void cb_SET_5_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf0,length=2
void cb_SET_6_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf1,length=2
void cb_SET_6_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf2,length=2
void cb_SET_6_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf3,length=2
void cb_SET_6_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf4,length=2
void cb_SET_6_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf5,length=2
void cb_SET_6_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xf6,length=2
void cb_SET_6__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf7,length=2
void cb_SET_6_A(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf8,length=2
void cb_SET_7_B(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xf9,length=2
void cb_SET_7_C(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xfa,length=2
void cb_SET_7_D(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xfb,length=2
void cb_SET_7_E(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xfc,length=2
void cb_SET_7_H(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xfd,length=2
void cb_SET_7_L(cpu_t* cpu, mem_t* mem);

// cycles=16,addr=0xfe,length=2
void cb_SET_7__OP_HL_CP_(cpu_t* cpu, mem_t* mem);

// cycles=8,addr=0xff,length=2
void cb_SET_7_A(cpu_t* cpu, mem_t* mem);

static const opcode_t normalOpcodes[NUM_NORMAL_OPCODES] = 
{
	/*0*/ &NOP,
	/*1*/ &LD_BC_d16,
	/*2*/ &LD__OP_BC_CP__A,
	/*3*/ &INC_BC,
	/*4*/ &INC_B,
	/*5*/ &DEC_B,
	/*6*/ &LD_B_d8,
	/*7*/ &RLCA,
	/*8*/ &LD__OP_a16_CP__SP,
	/*9*/ &ADD_HL_BC,
	/*10*/ &LD_A__OP_BC_CP_,
	/*11*/ &DEC_BC,
	/*12*/ &INC_C,
	/*13*/ &DEC_C,
	/*14*/ &LD_C_d8,
	/*15*/ &RRCA,
	/*16*/ &STOP_0,
	/*17*/ &LD_DE_d16,
	/*18*/ &LD__OP_DE_CP__A,
	/*19*/ &INC_DE,
	/*20*/ &INC_D,
	/*21*/ &DEC_D,
	/*22*/ &LD_D_d8,
	/*23*/ &RLA,
	/*24*/ &JR_r8,
	/*25*/ &ADD_HL_DE,
	/*26*/ &LD_A__OP_DE_CP_,
	/*27*/ &DEC_DE,
	/*28*/ &INC_E,
	/*29*/ &DEC_E,
	/*30*/ &LD_E_d8,
	/*31*/ &RRA,
	/*32*/ &JR_NZ_r8,
	/*33*/ &LD_HL_d16,
	/*34*/ &LD__OP_HL_PLUS__CP__A,
	/*35*/ &INC_HL,
	/*36*/ &INC_H,
	/*37*/ &DEC_H,
	/*38*/ &LD_H_d8,
	/*39*/ &DAA,
	/*40*/ &JR_Z_r8,
	/*41*/ &ADD_HL_HL,
	/*42*/ &LD_A__OP_HL_PLUS__CP_,
	/*43*/ &DEC_HL,
	/*44*/ &INC_L,
	/*45*/ &DEC_L,
	/*46*/ &LD_L_d8,
	/*47*/ &CPL,
	/*48*/ &JR_NC_r8,
	/*49*/ &LD_SP_d16,
	/*50*/ &LD__OP_HL_MINUS__CP__A,
	/*51*/ &INC_SP,
	/*52*/ &INC__OP_HL_CP_,
	/*53*/ &DEC__OP_HL_CP_,
	/*54*/ &LD__OP_HL_CP__d8,
	/*55*/ &SCF,
	/*56*/ &JR_C_r8,
	/*57*/ &ADD_HL_SP,
	/*58*/ &LD_A__OP_HL_MINUS__CP_,
	/*59*/ &DEC_SP,
	/*60*/ &INC_A,
	/*61*/ &DEC_A,
	/*62*/ &LD_A_d8,
	/*63*/ &CCF,
	/*64*/ &LD_B_B,
	/*65*/ &LD_B_C,
	/*66*/ &LD_B_D,
	/*67*/ &LD_B_E,
	/*68*/ &LD_B_H,
	/*69*/ &LD_B_L,
	/*70*/ &LD_B__OP_HL_CP_,
	/*71*/ &LD_B_A,
	/*72*/ &LD_C_B,
	/*73*/ &LD_C_C,
	/*74*/ &LD_C_D,
	/*75*/ &LD_C_E,
	/*76*/ &LD_C_H,
	/*77*/ &LD_C_L,
	/*78*/ &LD_C__OP_HL_CP_,
	/*79*/ &LD_C_A,
	/*80*/ &LD_D_B,
	/*81*/ &LD_D_C,
	/*82*/ &LD_D_D,
	/*83*/ &LD_D_E,
	/*84*/ &LD_D_H,
	/*85*/ &LD_D_L,
	/*86*/ &LD_D__OP_HL_CP_,
	/*87*/ &LD_D_A,
	/*88*/ &LD_E_B,
	/*89*/ &LD_E_C,
	/*90*/ &LD_E_D,
	/*91*/ &LD_E_E,
	/*92*/ &LD_E_H,
	/*93*/ &LD_E_L,
	/*94*/ &LD_E__OP_HL_CP_,
	/*95*/ &LD_E_A,
	/*96*/ &LD_H_B,
	/*97*/ &LD_H_C,
	/*98*/ &LD_H_D,
	/*99*/ &LD_H_E,
	/*100*/ &LD_H_H,
	/*101*/ &LD_H_L,
	/*102*/ &LD_H__OP_HL_CP_,
	/*103*/ &LD_H_A,
	/*104*/ &LD_L_B,
	/*105*/ &LD_L_C,
	/*106*/ &LD_L_D,
	/*107*/ &LD_L_E,
	/*108*/ &LD_L_H,
	/*109*/ &LD_L_L,
	/*110*/ &LD_L__OP_HL_CP_,
	/*111*/ &LD_L_A,
	/*112*/ &LD__OP_HL_CP__B,
	/*113*/ &LD__OP_HL_CP__C,
	/*114*/ &LD__OP_HL_CP__D,
	/*115*/ &LD__OP_HL_CP__E,
	/*116*/ &LD__OP_HL_CP__H,
	/*117*/ &LD__OP_HL_CP__L,
	/*118*/ &HALT,
	/*119*/ &LD__OP_HL_CP__A,
	/*120*/ &LD_A_B,
	/*121*/ &LD_A_C,
	/*122*/ &LD_A_D,
	/*123*/ &LD_A_E,
	/*124*/ &LD_A_H,
	/*125*/ &LD_A_L,
	/*126*/ &LD_A__OP_HL_CP_,
	/*127*/ &LD_A_A,
	/*128*/ &ADD_A_B,
	/*129*/ &ADD_A_C,
	/*130*/ &ADD_A_D,
	/*131*/ &ADD_A_E,
	/*132*/ &ADD_A_H,
	/*133*/ &ADD_A_L,
	/*134*/ &ADD_A__OP_HL_CP_,
	/*135*/ &ADD_A_A,
	/*136*/ &ADC_A_B,
	/*137*/ &ADC_A_C,
	/*138*/ &ADC_A_D,
	/*139*/ &ADC_A_E,
	/*140*/ &ADC_A_H,
	/*141*/ &ADC_A_L,
	/*142*/ &ADC_A__OP_HL_CP_,
	/*143*/ &ADC_A_A,
	/*144*/ &SUB_B,
	/*145*/ &SUB_C,
	/*146*/ &SUB_D,
	/*147*/ &SUB_E,
	/*148*/ &SUB_H,
	/*149*/ &SUB_L,
	/*150*/ &SUB__OP_HL_CP_,
	/*151*/ &SUB_A,
	/*152*/ &SBC_A_B,
	/*153*/ &SBC_A_C,
	/*154*/ &SBC_A_D,
	/*155*/ &SBC_A_E,
	/*156*/ &SBC_A_H,
	/*157*/ &SBC_A_L,
	/*158*/ &SBC_A__OP_HL_CP_,
	/*159*/ &SBC_A_A,
	/*160*/ &AND_B,
	/*161*/ &AND_C,
	/*162*/ &AND_D,
	/*163*/ &AND_E,
	/*164*/ &AND_H,
	/*165*/ &AND_L,
	/*166*/ &AND__OP_HL_CP_,
	/*167*/ &AND_A,
	/*168*/ &XOR_B,
	/*169*/ &XOR_C,
	/*170*/ &XOR_D,
	/*171*/ &XOR_E,
	/*172*/ &XOR_H,
	/*173*/ &XOR_L,
	/*174*/ &XOR__OP_HL_CP_,
	/*175*/ &XOR_A,
	/*176*/ &OR_B,
	/*177*/ &OR_C,
	/*178*/ &OR_D,
	/*179*/ &OR_E,
	/*180*/ &OR_H,
	/*181*/ &OR_L,
	/*182*/ &OR__OP_HL_CP_,
	/*183*/ &OR_A,
	/*184*/ &CP_B,
	/*185*/ &CP_C,
	/*186*/ &CP_D,
	/*187*/ &CP_E,
	/*188*/ &CP_H,
	/*189*/ &CP_L,
	/*190*/ &CP__OP_HL_CP_,
	/*191*/ &CP_A,
	/*192*/ &RET_NZ,
	/*193*/ &POP_BC,
	/*194*/ &JP_NZ_a16,
	/*195*/ &JP_a16,
	/*196*/ &CALL_NZ_a16,
	/*197*/ &PUSH_BC,
	/*198*/ &ADD_A_d8,
	/*199*/ &RST_00H,
	/*200*/ &RET_Z,
	/*201*/ &RET,
	/*202*/ &JP_Z_a16,
	/*203*/ &PREFIX_CB,
	/*204*/ &CALL_Z_a16,
	/*205*/ &CALL_a16,
	/*206*/ &ADC_A_d8,
	/*207*/ &RST_08H,
	/*208*/ &RET_NC,
	/*209*/ &POP_DE,
	/*210*/ &JP_NC_a16,
	/*211*/ &unusedFunc,
	/*212*/ &CALL_NC_a16,
	/*213*/ &PUSH_DE,
	/*214*/ &SUB_d8,
	/*215*/ &RST_10H,
	/*216*/ &RET_C,
	/*217*/ &RETI,
	/*218*/ &JP_C_a16,
	/*219*/ &unusedFunc,
	/*220*/ &CALL_C_a16,
	/*221*/ &unusedFunc,
	/*222*/ &SBC_A_d8,
	/*223*/ &RST_18H,
	/*224*/ &LDH__OP_a8_CP__A,
	/*225*/ &POP_HL,
	/*226*/ &LD__OP_C_CP__A,
	/*227*/ &unusedFunc,
	/*228*/ &unusedFunc,
	/*229*/ &PUSH_HL,
	/*230*/ &AND_d8,
	/*231*/ &RST_20H,
	/*232*/ &ADD_SP_r8,
	/*233*/ &JP__OP_HL_CP_,
	/*234*/ &LD__OP_a16_CP__A,
	/*235*/ &unusedFunc,
	/*236*/ &unusedFunc,
	/*237*/ &unusedFunc,
	/*238*/ &XOR_d8,
	/*239*/ &RST_28H,
	/*240*/ &LDH_A__OP_a8_CP_,
	/*241*/ &POP_AF,
	/*242*/ &LD_A__OP_C_CP_,
	/*243*/ &DI,
	/*244*/ &unusedFunc,
	/*245*/ &PUSH_AF,
	/*246*/ &OR_d8,
	/*247*/ &RST_30H,
	/*248*/ &LD_HL_SP_PLUS_r8,
	/*249*/ &LD_SP_HL,
	/*250*/ &LD_A__OP_a16_CP_,
	/*251*/ &EI,
	/*252*/ &unusedFunc,
	/*253*/ &unusedFunc,
	/*254*/ &CP_d8,
	/*255*/ &RST_38H,
};


static const opcode_t cbOpcodes[NUM_CB_OPCODES] = 
{
	/*0*/ &cb_RLC_B,
	/*1*/ &cb_RLC_C,
	/*2*/ &cb_RLC_D,
	/*3*/ &cb_RLC_E,
	/*4*/ &cb_RLC_H,
	/*5*/ &cb_RLC_L,
	/*6*/ &cb_RLC__OP_HL_CP_,
	/*7*/ &cb_RLC_A,
	/*8*/ &cb_RRC_B,
	/*9*/ &cb_RRC_C,
	/*10*/ &cb_RRC_D,
	/*11*/ &cb_RRC_E,
	/*12*/ &cb_RRC_H,
	/*13*/ &cb_RRC_L,
	/*14*/ &cb_RRC__OP_HL_CP_,
	/*15*/ &cb_RRC_A,
	/*16*/ &cb_RL_B,
	/*17*/ &cb_RL_C,
	/*18*/ &cb_RL_D,
	/*19*/ &cb_RL_E,
	/*20*/ &cb_RL_H,
	/*21*/ &cb_RL_L,
	/*22*/ &cb_RL__OP_HL_CP_,
	/*23*/ &cb_RL_A,
	/*24*/ &cb_RR_B,
	/*25*/ &cb_RR_C,
	/*26*/ &cb_RR_D,
	/*27*/ &cb_RR_E,
	/*28*/ &cb_RR_H,
	/*29*/ &cb_RR_L,
	/*30*/ &cb_RR__OP_HL_CP_,
	/*31*/ &cb_RR_A,
	/*32*/ &cb_SLA_B,
	/*33*/ &cb_SLA_C,
	/*34*/ &cb_SLA_D,
	/*35*/ &cb_SLA_E,
	/*36*/ &cb_SLA_H,
	/*37*/ &cb_SLA_L,
	/*38*/ &cb_SLA__OP_HL_CP_,
	/*39*/ &cb_SLA_A,
	/*40*/ &cb_SRA_B,
	/*41*/ &cb_SRA_C,
	/*42*/ &cb_SRA_D,
	/*43*/ &cb_SRA_E,
	/*44*/ &cb_SRA_H,
	/*45*/ &cb_SRA_L,
	/*46*/ &cb_SRA__OP_HL_CP_,
	/*47*/ &cb_SRA_A,
	/*48*/ &cb_SWAP_B,
	/*49*/ &cb_SWAP_C,
	/*50*/ &cb_SWAP_D,
	/*51*/ &cb_SWAP_E,
	/*52*/ &cb_SWAP_H,
	/*53*/ &cb_SWAP_L,
	/*54*/ &cb_SWAP__OP_HL_CP_,
	/*55*/ &cb_SWAP_A,
	/*56*/ &cb_SRL_B,
	/*57*/ &cb_SRL_C,
	/*58*/ &cb_SRL_D,
	/*59*/ &cb_SRL_E,
	/*60*/ &cb_SRL_H,
	/*61*/ &cb_SRL_L,
	/*62*/ &cb_SRL__OP_HL_CP_,
	/*63*/ &cb_SRL_A,
	/*64*/ &cb_BIT_0_B,
	/*65*/ &cb_BIT_0_C,
	/*66*/ &cb_BIT_0_D,
	/*67*/ &cb_BIT_0_E,
	/*68*/ &cb_BIT_0_H,
	/*69*/ &cb_BIT_0_L,
	/*70*/ &cb_BIT_0__OP_HL_CP_,
	/*71*/ &cb_BIT_0_A,
	/*72*/ &cb_BIT_1_B,
	/*73*/ &cb_BIT_1_C,
	/*74*/ &cb_BIT_1_D,
	/*75*/ &cb_BIT_1_E,
	/*76*/ &cb_BIT_1_H,
	/*77*/ &cb_BIT_1_L,
	/*78*/ &cb_BIT_1__OP_HL_CP_,
	/*79*/ &cb_BIT_1_A,
	/*80*/ &cb_BIT_2_B,
	/*81*/ &cb_BIT_2_C,
	/*82*/ &cb_BIT_2_D,
	/*83*/ &cb_BIT_2_E,
	/*84*/ &cb_BIT_2_H,
	/*85*/ &cb_BIT_2_L,
	/*86*/ &cb_BIT_2__OP_HL_CP_,
	/*87*/ &cb_BIT_2_A,
	/*88*/ &cb_BIT_3_B,
	/*89*/ &cb_BIT_3_C,
	/*90*/ &cb_BIT_3_D,
	/*91*/ &cb_BIT_3_E,
	/*92*/ &cb_BIT_3_H,
	/*93*/ &cb_BIT_3_L,
	/*94*/ &cb_BIT_3__OP_HL_CP_,
	/*95*/ &cb_BIT_3_A,
	/*96*/ &cb_BIT_4_B,
	/*97*/ &cb_BIT_4_C,
	/*98*/ &cb_BIT_4_D,
	/*99*/ &cb_BIT_4_E,
	/*100*/ &cb_BIT_4_H,
	/*101*/ &cb_BIT_4_L,
	/*102*/ &cb_BIT_4__OP_HL_CP_,
	/*103*/ &cb_BIT_4_A,
	/*104*/ &cb_BIT_5_B,
	/*105*/ &cb_BIT_5_C,
	/*106*/ &cb_BIT_5_D,
	/*107*/ &cb_BIT_5_E,
	/*108*/ &cb_BIT_5_H,
	/*109*/ &cb_BIT_5_L,
	/*110*/ &cb_BIT_5__OP_HL_CP_,
	/*111*/ &cb_BIT_5_A,
	/*112*/ &cb_BIT_6_B,
	/*113*/ &cb_BIT_6_C,
	/*114*/ &cb_BIT_6_D,
	/*115*/ &cb_BIT_6_E,
	/*116*/ &cb_BIT_6_H,
	/*117*/ &cb_BIT_6_L,
	/*118*/ &cb_BIT_6__OP_HL_CP_,
	/*119*/ &cb_BIT_6_A,
	/*120*/ &cb_BIT_7_B,
	/*121*/ &cb_BIT_7_C,
	/*122*/ &cb_BIT_7_D,
	/*123*/ &cb_BIT_7_E,
	/*124*/ &cb_BIT_7_H,
	/*125*/ &cb_BIT_7_L,
	/*126*/ &cb_BIT_7__OP_HL_CP_,
	/*127*/ &cb_BIT_7_A,
	/*128*/ &cb_RES_0_B,
	/*129*/ &cb_RES_0_C,
	/*130*/ &cb_RES_0_D,
	/*131*/ &cb_RES_0_E,
	/*132*/ &cb_RES_0_H,
	/*133*/ &cb_RES_0_L,
	/*134*/ &cb_RES_0__OP_HL_CP_,
	/*135*/ &cb_RES_0_A,
	/*136*/ &cb_RES_1_B,
	/*137*/ &cb_RES_1_C,
	/*138*/ &cb_RES_1_D,
	/*139*/ &cb_RES_1_E,
	/*140*/ &cb_RES_1_H,
	/*141*/ &cb_RES_1_L,
	/*142*/ &cb_RES_1__OP_HL_CP_,
	/*143*/ &cb_RES_1_A,
	/*144*/ &cb_RES_2_B,
	/*145*/ &cb_RES_2_C,
	/*146*/ &cb_RES_2_D,
	/*147*/ &cb_RES_2_E,
	/*148*/ &cb_RES_2_H,
	/*149*/ &cb_RES_2_L,
	/*150*/ &cb_RES_2__OP_HL_CP_,
	/*151*/ &cb_RES_2_A,
	/*152*/ &cb_RES_3_B,
	/*153*/ &cb_RES_3_C,
	/*154*/ &cb_RES_3_D,
	/*155*/ &cb_RES_3_E,
	/*156*/ &cb_RES_3_H,
	/*157*/ &cb_RES_3_L,
	/*158*/ &cb_RES_3__OP_HL_CP_,
	/*159*/ &cb_RES_3_A,
	/*160*/ &cb_RES_4_B,
	/*161*/ &cb_RES_4_C,
	/*162*/ &cb_RES_4_D,
	/*163*/ &cb_RES_4_E,
	/*164*/ &cb_RES_4_H,
	/*165*/ &cb_RES_4_L,
	/*166*/ &cb_RES_4__OP_HL_CP_,
	/*167*/ &cb_RES_4_A,
	/*168*/ &cb_RES_5_B,
	/*169*/ &cb_RES_5_C,
	/*170*/ &cb_RES_5_D,
	/*171*/ &cb_RES_5_E,
	/*172*/ &cb_RES_5_H,
	/*173*/ &cb_RES_5_L,
	/*174*/ &cb_RES_5__OP_HL_CP_,
	/*175*/ &cb_RES_5_A,
	/*176*/ &cb_RES_6_B,
	/*177*/ &cb_RES_6_C,
	/*178*/ &cb_RES_6_D,
	/*179*/ &cb_RES_6_E,
	/*180*/ &cb_RES_6_H,
	/*181*/ &cb_RES_6_L,
	/*182*/ &cb_RES_6__OP_HL_CP_,
	/*183*/ &cb_RES_6_A,
	/*184*/ &cb_RES_7_B,
	/*185*/ &cb_RES_7_C,
	/*186*/ &cb_RES_7_D,
	/*187*/ &cb_RES_7_E,
	/*188*/ &cb_RES_7_H,
	/*189*/ &cb_RES_7_L,
	/*190*/ &cb_RES_7__OP_HL_CP_,
	/*191*/ &cb_RES_7_A,
	/*192*/ &cb_SET_0_B,
	/*193*/ &cb_SET_0_C,
	/*194*/ &cb_SET_0_D,
	/*195*/ &cb_SET_0_E,
	/*196*/ &cb_SET_0_H,
	/*197*/ &cb_SET_0_L,
	/*198*/ &cb_SET_0__OP_HL_CP_,
	/*199*/ &cb_SET_0_A,
	/*200*/ &cb_SET_1_B,
	/*201*/ &cb_SET_1_C,
	/*202*/ &cb_SET_1_D,
	/*203*/ &cb_SET_1_E,
	/*204*/ &cb_SET_1_H,
	/*205*/ &cb_SET_1_L,
	/*206*/ &cb_SET_1__OP_HL_CP_,
	/*207*/ &cb_SET_1_A,
	/*208*/ &cb_SET_2_B,
	/*209*/ &cb_SET_2_C,
	/*210*/ &cb_SET_2_D,
	/*211*/ &cb_SET_2_E,
	/*212*/ &cb_SET_2_H,
	/*213*/ &cb_SET_2_L,
	/*214*/ &cb_SET_2__OP_HL_CP_,
	/*215*/ &cb_SET_2_A,
	/*216*/ &cb_SET_3_B,
	/*217*/ &cb_SET_3_C,
	/*218*/ &cb_SET_3_D,
	/*219*/ &cb_SET_3_E,
	/*220*/ &cb_SET_3_H,
	/*221*/ &cb_SET_3_L,
	/*222*/ &cb_SET_3__OP_HL_CP_,
	/*223*/ &cb_SET_3_A,
	/*224*/ &cb_SET_4_B,
	/*225*/ &cb_SET_4_C,
	/*226*/ &cb_SET_4_D,
	/*227*/ &cb_SET_4_E,
	/*228*/ &cb_SET_4_H,
	/*229*/ &cb_SET_4_L,
	/*230*/ &cb_SET_4__OP_HL_CP_,
	/*231*/ &cb_SET_4_A,
	/*232*/ &cb_SET_5_B,
	/*233*/ &cb_SET_5_C,
	/*234*/ &cb_SET_5_D,
	/*235*/ &cb_SET_5_E,
	/*236*/ &cb_SET_5_H,
	/*237*/ &cb_SET_5_L,
	/*238*/ &cb_SET_5__OP_HL_CP_,
	/*239*/ &cb_SET_5_A,
	/*240*/ &cb_SET_6_B,
	/*241*/ &cb_SET_6_C,
	/*242*/ &cb_SET_6_D,
	/*243*/ &cb_SET_6_E,
	/*244*/ &cb_SET_6_H,
	/*245*/ &cb_SET_6_L,
	/*246*/ &cb_SET_6__OP_HL_CP_,
	/*247*/ &cb_SET_6_A,
	/*248*/ &cb_SET_7_B,
	/*249*/ &cb_SET_7_C,
	/*250*/ &cb_SET_7_D,
	/*251*/ &cb_SET_7_E,
	/*252*/ &cb_SET_7_H,
	/*253*/ &cb_SET_7_L,
	/*254*/ &cb_SET_7__OP_HL_CP_,
	/*255*/ &cb_SET_7_A,
};


#endif

