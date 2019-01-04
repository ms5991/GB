#include "test_cpu_eightbit_alu.h"
#include "components.h"
#include "cpu.h"
#include <assert.h>
#include <stdio.h>

#define VERIFY_FLAGS(cpuAddr, intendedZ, intendedN, intendedH, intendedC)({\
    assert(getFlag(cpuAddr, flag_Z) == intendedZ); \
    assert(getFlag(cpuAddr, flag_N) == intendedN); \
    assert(getFlag(cpuAddr, flag_H) == intendedH); \
    assert(getFlag(cpuAddr, flag_C) == intendedC); \
})

cpu_t getTestCpu()
{
    cpu_t result;
    initCpu(&result);

    return result;
}

void testEightBitIncFromZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0;
    
    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_INC);

    // incremented from 0 to 1
    assert(cpu.reg_A == (initialValue + 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitIncWithHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0xF;

    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_INC);

    // incremented from 15 to 16
    assert(cpu.reg_A == (initialValue + 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitIncWithoutHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x14;
    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_INC);

    // incremented from 20 to 21
    assert(cpu.reg_A == (initialValue + 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitDecToZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x01;

    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_DEC);

    // decremented from 1 to 0
    assert(cpu.reg_A == (initialValue - 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitDecWithHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;

    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_DEC);

    // decremented from 16 to 15
    assert(cpu.reg_A == (initialValue - 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitDecWithoutHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x15;

    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, 1, ALU_DEC);

    // decremented from 21 to 20
    assert(cpu.reg_A == (initialValue - 1));

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAddFromZeroToZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x00;

    cpu.reg_A = initialValue;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_A, ALU_ADD);

    // added zero to zero
    assert(cpu.reg_A == initialValue);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAddFromZeroToNonZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x00;
    uint8_t toAdd = 0x05;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAdd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_ADD);

    // added zero to nonzero
    assert(cpu.reg_A == toAdd);

    // make sure B is unchanged
    assert(cpu.reg_B == toAdd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAddFromNonZeroToNonZeroNoHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x01;
    uint8_t toAdd = 0x05;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAdd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_ADD);

    // added zero to nonzero
    assert(cpu.reg_A == (initialValue + toAdd));

    // make sure B is unchanged
    assert(cpu.reg_B == toAdd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAddFromNonZeroToNonZeroWithHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x0F;
    uint8_t toAdd = 0x05;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAdd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_ADD);

    // added zero to nonzero
    assert(cpu.reg_A == (initialValue + toAdd));

    // make sure B is unchanged
    assert(cpu.reg_B == toAdd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAddFromNonZeroToNonZeroWithFullCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0xFF;
    uint8_t toAdd = 0x05;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAdd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_ADD);

    uint8_t correctValue = (initialValue + toAdd);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toAdd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void runAllEightBitALUTests()
{
    testEightBitIncFromZero();
    testEightBitIncWithHalfCarry();
    testEightBitIncWithoutHalfCarry();
    testEightBitDecToZero();
    testEightBitDecWithHalfCarry();
    testEightBitDecWithoutHalfCarry();
    testEightBitAddFromZeroToZero();
    testEightBitAddFromZeroToNonZero();
    testEightBitAddFromNonZeroToNonZeroNoHalfCarry();
    testEightBitAddFromNonZeroToNonZeroWithHalfCarry();
    testEightBitAddFromNonZeroToNonZeroWithFullCarry();
}