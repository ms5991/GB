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
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_SET, FLAG_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitSubFromNonZeroToZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x0F;
    uint8_t toSub = 0x0F;

    cpu.reg_A = initialValue;
    cpu.reg_B = toSub;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_SUB);

    uint8_t correctValue = (initialValue - toSub);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toSub);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitSubFromNonZeroToNonZeroNoCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x0F;
    uint8_t toSub = 0x0E;

    cpu.reg_A = initialValue;
    cpu.reg_B = toSub;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_SUB);

    uint8_t correctValue = (initialValue - toSub);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toSub);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitSubFromNonZeroToNonZeroWithHalfCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toSub = 0x0E;

    cpu.reg_A = initialValue;
    cpu.reg_B = toSub;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_SUB);

    uint8_t correctValue = (initialValue - toSub);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toSub);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitSubFromNonZeroToNonZeroWithFullCarry()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toSub = 0xFF;

    cpu.reg_A = initialValue;
    cpu.reg_B = toSub;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_SUB);

    uint8_t correctValue = (initialValue - toSub);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toSub);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_SET, FLAG_SET, FLAG_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAndNonZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toAnd = 0x10;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAnd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_AND);

    uint8_t correctValue = (initialValue & toAnd);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toAnd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAndZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toAnd = 0x01;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAnd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_AND);

    uint8_t correctValue = (initialValue & toAnd);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toAnd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitAndAllOpsZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x0;
    uint8_t toAnd = 0x0;

    cpu.reg_A = initialValue;
    cpu.reg_B = toAnd;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_AND);

    uint8_t correctValue = (initialValue & toAnd);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toAnd);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitOrNonZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toOr = 0x00;

    cpu.reg_A = initialValue;
    cpu.reg_B = toOr;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_OR);

    uint8_t correctValue = (initialValue | toOr);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toOr);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitOrZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x00;
    uint8_t toOr = 0x00;

    cpu.reg_A = initialValue;
    cpu.reg_B = toOr;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_OR);

    uint8_t correctValue = (initialValue | toOr);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toOr);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitXorNonZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toXor = 0x01;

    cpu.reg_A = initialValue;
    cpu.reg_B = toXor;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_XOR);

    uint8_t correctValue = (initialValue ^ toXor);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toXor);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitXorZeroResult()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x10;
    uint8_t toXor = 0x10;

    cpu.reg_A = initialValue;
    cpu.reg_B = toXor;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_XOR);

    uint8_t correctValue = (initialValue ^ toXor);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toXor);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

    printf("Test function passed: [%s]\n", __func__);
}

void testEightBitXorAllOpsZero()
{
    cpu_t cpu = getTestCpu();
    uint8_t initialValue = 0x00;
    uint8_t toXor = 0x00;

    cpu.reg_A = initialValue;
    cpu.reg_B = toXor;

    executeEightBitALUOp(&cpu, &cpu.reg_A, cpu.reg_A, cpu.reg_B, ALU_XOR);

    uint8_t correctValue = (initialValue ^ toXor);

    // added zero to nonzero
    assert(cpu.reg_A == correctValue);

    // make sure B is unchanged
    assert(cpu.reg_B == toXor);

    // Z (zero), N (sub) H (half carry) C (carry)
    VERIFY_FLAGS(&cpu, FLAG_SET, FLAG_NOT_SET, FLAG_NOT_SET, FLAG_NOT_SET);

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
    testEightBitSubFromNonZeroToZero();
    testEightBitSubFromNonZeroToNonZeroNoCarry();
    testEightBitSubFromNonZeroToNonZeroWithHalfCarry();
    testEightBitSubFromNonZeroToNonZeroWithFullCarry();
    testEightBitAndNonZeroResult();
    testEightBitAndZeroResult();
    testEightBitAndAllOpsZero();
    testEightBitOrNonZeroResult();
    testEightBitOrZeroResult();
    testEightBitXorNonZeroResult();
    testEightBitXorZeroResult();
    testEightBitXorAllOpsZero();
}