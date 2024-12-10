#pragma once
#include "risc_int.hpp"
#include "risc_v_common.hpp"

namespace rgemu::risa {

enum class RV32I_Type { Register, Immediate, Store, Branch, UImmediate, Jump };

using RV32I_R_Register = base::uint5_t;
using RV32I_R_Opcode   = base::uint7_t;
using RV32I_R_Funct3   = base::uint3_t;
using RV32I_R_Funct7   = base::uint7_t;

enum class RV32I_R_Opcodes_type : uint8_t {
  R_add  = 0b0110011,
  R_sub  = 0b0110011,
  R_sll  = 0b0000000,
  R_slt  = 0b0000000,
  R_sltu = 0b0000000,
  R_xor  = 0b0110011,
  R_srl  = 0b0000000,
  R_sra  = 0b0000000,
  R_or   = 0b0110011,
  R_and  = 0b0110011
};

struct RV32I_R_ABI {
  RV32I_R_Opcode   opcode;
  RV32I_R_Register rd;
  RV32I_R_Funct3   funct3;
  RV32I_R_Register rs1, rs2;
  RV32I_R_Funct7   funct7;
};

};  // namespace rgemu::risa