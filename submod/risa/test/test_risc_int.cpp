#include <gtest/gtest.h>
#include <risa/isa_impl.hpp>
#include <risa/op_codes.hpp>

TEST(risa, executeInstruction) {
  // mock instrcut opcode for ADDI type
  // which imm = 19, rs1 = 3, rd = 4
  rgemu::risa::OpCodeCell  opcode = 0x01318213;  // ADDI x0, x0, 3
  rgemu::risa::instruction instr(opcode);
  ASSERT_EQ(instr.type, rgemu::risa::instruction_type::I_type);
  ASSERT_EQ(instr.rd, 4);   // Destination register x0
  ASSERT_EQ(instr.rs1, 3);  // Source register x0
  ASSERT_EQ(instr.funct3,
            static_cast<uint8_t>(
                rgemu::risa::I_Type_Opcode::ADDI));  // Function code for ADDI
  ASSERT_EQ(instr.imm, 19);
}