#pragma once
#include "risc_v_common.hpp"

namespace rgemu::risa {

/// @brief RISC-V 32-bit I-type instruction set.
/// @details This is a C++ enum class that represents opcode type of the RISC-V 32-bit I-type Base instruction set.
/// @see http://staff.ustc.edu.cn/~llxx/cod/reference_books/RISC-V-Reader-Chinese-v2p12017.pdf
enum class RV32I_OpcodeType : uint8_t {
  U_lui     = 0b0110111,
  U_auipc   = 0b0010111,
  J_jal     = 0b1101111,
  B_beq     = 0b1100011,
  B_bne     = 0b1100011,
  B_blt     = 0b1100011,
  B_bge     = 0b1100011,
  B_bltu    = 0b1100011,
  B_bgeu    = 0b1100011,
  I_lb      = 0b0000011,
  I_lh      = 0b0000011,
  I_lw      = 0b0000011,
  I_lbu     = 0b0000011,
  I_lhu     = 0b0000011,
  S_sb      = 0b0100011,
  S_sh      = 0b0100011,
  S_sw      = 0b0100011,
  I_addi    = 0b0010011,
  I_slti    = 0b0010011,
  I_sltiu   = 0b0010011,
  I_xori    = 0b0010011,
  I_ori     = 0b0010011,
  I_andi    = 0b0010011,
  I_slli    = 0b0010011,
  I_srli    = 0b0010011,
  I_srai    = 0b0010011,
  R_add     = 0b0110011,
  R_sub     = 0b0110011,
  R_sll     = 0b0110011,
  R_slt     = 0b0110011,
  R_sltu    = 0b0110011,
  R_xor     = 0b0110011,
  R_srl     = 0b0110011,
  R_sra     = 0b0110011,
  R_or      = 0b0110011,
  R_and     = 0b0110011,
  I_fence   = 0b0001111,
  I_fence_i = 0b0001111,
  I_ecall   = 0b1110011,
  I_ebreak  = 0b1110011,
  I_csrrw   = 0b1110011,
  I_csrrs   = 0b1110011,
  I_csrrc   = 0b1110011,
  I_csrrwi  = 0b1110011,
  I_csrrsi  = 0b1110011,
  I_csrrci  = 0b1110011
};

/// @brief RISC-V 32-bit I-type R instruction format.
struct RV32I_R_Instruction {
  uint8_t opcode : 7;
  uint8_t rd : 5;
  uint8_t funct3 : 3;
  uint8_t rs1 : 5;
  uint8_t rs2 : 5;
  uint8_t funct7 : 7;
};

/// @brief RISC-V 32-bit I-type I instruction format.
struct RV32I_I_Instruction {
  uint8_t  opcode : 7;
  uint8_t  rd : 5;
  uint8_t  funct3 : 3;
  uint8_t  rs1 : 5;
  uint16_t imm : 12;
};

/// @brief RISC-V 32-bit I-type S instruction format.
struct RV32I_S_Instruction {
  uint8_t  opcode : 7;
  uint8_t  imm1 : 5;
  uint8_t  funct3 : 3;
  uint8_t  rs1 : 5;
  uint8_t  rs2 : 5;
  uint16_t imm2 : 7;
};

/// @brief RISC-V 32-bit I-type B instruction format.
struct RV32I_B_Instruction {
  uint8_t  opcode : 7;
  uint8_t  imm1 : 5;
  uint8_t  funct3 : 3;
  uint8_t  rs1 : 5;
  uint8_t  rs2 : 5;
  uint16_t imm2 : 8;
};

/// @brief RISC-V 32-bit I-type U instruction format.
struct RV32I_U_Instruction {
  uint8_t  opcode : 7;
  uint8_t  rd : 5;
  uint32_t imm : 20;
};

/// @brief RISC-V 32-bit I-type J instruction format.
struct RV32I_J_Instruction {
  uint8_t  opcode : 7;    // Opcode (bits 6-0)
  uint8_t  rd : 5;        // Destination register (bits 11-7)
  uint8_t  imm19_12 : 8;  // Immediate value bits 19-12 (bits 19-12)
  uint8_t  imm11 : 1;     // Immediate value bit 11 (bit 20)
  uint16_t imm10_1 : 10;  // Immediate value bits 10-1 (bits 30-21)
  uint8_t  imm20 : 1;     // Immediate value bit 20 (bit 31)
};

void U_lui(const uint32_t& instr);
void U_auipc(const uint32_t& instr);
void J_jal(const uint32_t& instr);
void B_beq(const uint32_t& instr);
void B_bne(const uint32_t& instr);
void B_blt(const uint32_t& instr);
void B_bge(const uint32_t& instr);
void B_bltu(const uint32_t& instr);
void B_bgeu(const uint32_t& instr);
void I_lb(const uint32_t& instr);
void I_lh(const uint32_t& instr);
void I_lw(const uint32_t& instr);
void I_lbu(const uint32_t& instr);
void I_lhu(const uint32_t& instr);
void S_sb(const uint32_t& instr);
void S_sh(const uint32_t& instr);
void S_sw(const uint32_t& instr);
void I_addi(const uint32_t& instr);
void I_slti(const uint32_t& instr);
void I_sltiu(const uint32_t& instr);
void I_xori(const uint32_t& instr);
void I_ori(const uint32_t& instr);
void I_andi(const uint32_t& instr);
void I_slli(const uint32_t& instr);
void I_srli(const uint32_t& instr);
void I_srai(const uint32_t& instr);
void R_add(const uint32_t& instr);
void R_sub(const uint32_t& instr);
void R_sll(const uint32_t& instr);
void R_slt(const uint32_t& instr);
void R_sltu(const uint32_t& instr);
void R_xor(const uint32_t& instr);
void R_srl(const uint32_t& instr);
void R_sra(const uint32_t& instr);
void R_or(const uint32_t& instr);
void R_and(const uint32_t& instr);
void I_fence(const uint32_t& instr);
void I_fence_i(const uint32_t& instr);
void I_ecall(const uint32_t& instr);
void I_ebreak(const uint32_t& instr);
void I_csrrw(const uint32_t& instr);
void I_csrrs(const uint32_t& instr);
void I_csrrc(const uint32_t& instr);
void I_csrrwi(const uint32_t& instr);
void I_csrrsi(const uint32_t& instr);
void I_csrrci(const uint32_t& instr);

};  // namespace rgemu::risa