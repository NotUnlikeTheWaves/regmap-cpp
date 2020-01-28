#include "registermap.hpp"
#include "gtest/gtest.h"

TEST(RegisterMapTests, EqualityTest) {
    RegisterMap<uint16_t, 0xff> rm;
    uint16_t& regA = rm.createRegister(0x10);
    uint16_t& regB = rm.createRegister(0x10);

    // Write 24 to the register at 0x10
    regA = 24;

    // Read 24 at both the same and another register, both on the same address
    ASSERT_EQ(regA, 24);
    ASSERT_EQ(regB, 24);
}

TEST(RegisterMapTests, SubRegister) {
    // Create a new register map containing 0xff uint16_t-s
    RegisterMap<uint16_t, 0xff> rm;
    // Create a control register
    uint16_t& regA = rm.createRegister(0x10);
    // Create an actual sub type register
    SubTypeRegister<uint16_t, 8> subReg = rm.createSubTypeRegister<8>(0x10, 2);

    // Write 32 to this register, then read it out in val.
    subReg = 32;

    int val = subReg;

    // Assert the actual register is written the right value to
    ASSERT_EQ(regA, 32 << 2);
    // Assert that val is correctly read
    ASSERT_EQ(val, 32);
}

TEST(RegisterMapTests, OverFlows) {
    // Create a new register map containing 0xff uint16_t-s
    RegisterMap<uint16_t, 0xff> rm;
    // Create a control register
    uint16_t& regA = rm.createRegister(0x10);
    // Create an actual sub type register
    SubTypeRegister<uint16_t, 2> subReg = rm.createSubTypeRegister<2>(0x10, 2);
    // Write 5 to this register, i.e. 101 in binary. This should eventually store 01 in this register.
    subReg = 5;

    int val = subReg;

    // Assert that the value from the subRegister is 1, in line with the overflow.
    ASSERT_EQ(val, 1);
    // Assert that the value in regA is 01 << 2, i.e. 4:
    ASSERT_EQ(regA, 4);
}
