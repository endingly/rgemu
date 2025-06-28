#pragma once
#include <cstdint>

namespace rgemu::risa {

using OpCodeCell = uint32_t;

enum class instruction_type : uint8_t {
  R_type = 0b0110011,
  I_type = 0b0010011,
  S_type = 0b0100011,
  B_type = 0b1100011,
  U_type = 0b0110111,
  J_type = 0b1101111,
  System = 0b1110011
};

/// @brief RISC-V 32-bit instruction set.
/// This struct represents a RISC-V instruction in a simplified format.
/// | funct7[31:25] | rs2[24:20] | rs1[19:15] | funct3[14:12] | rd[11:7] | opcode[6:0] |
/// |          imm[31:20]        | rs1[19:15] | funct3[14:12] | rd[11:7] | opcode[6:0] |
struct instruction {
  const OpCodeCell       op_code;
  const instruction_type type;    // Instruction type based on opcode
  const uint8_t          rd;      // Destination register
  const uint8_t          rs1;     // Source register 1
  const uint8_t          rs2;     // Source register 2
  const uint8_t          funct3;  // Function code for the operation
  const uint8_t          funct7;  // Additional function code for R-type instructions
  const uint32_t         imm;     // Immediate value
  const uint8_t          shamt;   // Shift amount for shift instructions

  instruction(OpCodeCell inst_code)
      : op_code(inst_code),
        type(parse_op_type(op_code)),
        rd(parse_rd(op_code)),
        rs1(parse_rs1(op_code)),
        rs2(parse_rs2(op_code)),
        funct3(parse_funct3(op_code)),
        funct7(parse_funct7(op_code)),
        imm(parse_imm(op_code)),
        shamt(parse_shamt(op_code)) {}

 private:
  instruction_type parse_op_type(OpCodeCell op_code) { return static_cast<instruction_type>(op_code & 0b0111111); }

  uint8_t parse_rd(OpCodeCell inst_code) {
    if (type == instruction_type::J_type || type == instruction_type::U_type || type == instruction_type::R_type ||
        type == instruction_type::I_type) {
      return (inst_code >> 7) & 0b11111;  // Extract bits 11-7 for J-type
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint8_t parse_rs1(OpCodeCell inst_code) {
    if (type == instruction_type::R_type || type == instruction_type::I_type || type == instruction_type::S_type ||
        type == instruction_type::B_type) {
      return (inst_code >> 15) & 0b11111;  // Extract bits 19-15
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint8_t parse_rs2(OpCodeCell inst_code) {
    if (type == instruction_type::R_type || type == instruction_type::S_type || type == instruction_type::B_type) {
      return (inst_code >> 20) & 0b11111;  // Extract bits 24-20
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint8_t parse_funct3(OpCodeCell inst_code) {
    if (type == instruction_type::R_type || type == instruction_type::I_type || type == instruction_type::S_type ||
        type == instruction_type::B_type) {
      return (inst_code >> 12) & 0b111;  // Extract bits 14-12
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint8_t parse_funct7(OpCodeCell inst_code) {
    if (type == instruction_type::R_type) {
      return (inst_code >> 25) & 0b1111111;  // Extract bits 31-25
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint32_t parse_imm(OpCodeCell inst) {
    if (type == instruction_type::I_type) {
      return (inst >> 20) & 0xfff;  // Extract bits 31-20
    } else if (type == instruction_type::S_type) {
      return ((inst >> 20) & 0xfe0) | ((inst >> 7) & 0x1f);  // Extract bits 31-25 and 11-7, combine them
    } else if (type == instruction_type::B_type) {
      return ((inst >> 19) & 0x1000)   // imm[12] = inst[31];
             | ((inst & 0x80) << 4)    // imm[11] = inst[7];
             | ((inst >> 20) & 0x7e0)  // imm[10:5] = inst[30:25];
             | ((inst >> 7) & 0x1e);   // imm[4:1] = inst[11:8]
    } else if (type == instruction_type::U_type) {
      return inst & 0xFFFFF000;  // Extract bits 31-12
    } else if (type == instruction_type::J_type) {
      // imm[20|10:1|11|19:12] = inst[31|30:21|20|19:12]
      return ((inst >> 12) & 0x80000)   // imm[20] = inst[31];
             | ((inst >> 20) & 0x7FE)   // imm[10:1] = inst[30:21];
             | ((inst >> 9) & 0x800)    // imm[11] = inst[20];
             | ((inst >> 21) & 0x7FF);  // imm[19:12] = inst[19:12];
    } else {
      return 0;  // default case and should not happen
    }
  }

  uint32_t parse_shamt(OpCodeCell inst) {
    // shamt(shift amount) only required for immediate shift instructions
    // shamt[4:5] = imm[5:0]
    return (imm & 0x1f);  // TODO: 0x1f / 0x3f ?
  }
};

};  // namespace rgemu::risa