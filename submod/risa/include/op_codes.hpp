#pragma once
#include <cstdint>
#include <unordered_map>
#include "isa_impl.hpp"

namespace rgemu::risa {

// clang-format off

/// @brief RISC-V 32-bit instruction set opcodes for I-type instructions.
/// @note contains the opcodes for func3 and func7 fields of I-type instructions.
enum class I_Type_Opcode : uint8_t {
  ADDI  = 0x0,
  SLLT  = 0x1,
  SLTI  = 0x2,
  SLTIU = 0x3,
  XORI  = 0x4,
  SRI   = 0x5,   // Shift Right Immediate
    SRLI  = 0x00,  // Shift Right Logical Immediate
    SRAI  = 0x20,  // Shift Right Arithmetic Immediate
  ORI   = 0x6,
  ANDI  = 0x7
};

// clang-format on

namespace inst_set {

using HardwareType = rgemu::risa::interface::isa_impl::HardwareType;
using ISA_FUNC     = void (*)(HardwareType&, instruction&);

/* isa defined start */

void ADDI(HardwareType& hardware, instruction& inst);
void SLTI(HardwareType& hardware, instruction& inst);
void SLTIU(HardwareType& hardware, instruction& inst);
void XORI(HardwareType& hardware, instruction& inst);
void ORI(HardwareType& hardware, instruction& inst);
void ANDI(HardwareType& hardware, instruction& inst);
void SLLI(HardwareType& hardware, instruction& inst);
void SRLI(HardwareType& hardware, instruction& inst);
void SRAI(HardwareType& hardware, instruction& inst);

static std::unordered_map<I_Type_Opcode, ISA_FUNC> I_Type_Opcode_Functions = {
    {I_Type_Opcode::ADDI, ADDI},   {I_Type_Opcode::SLTI, SLTI},
    {I_Type_Opcode::SLTIU, SLTIU}, {I_Type_Opcode::XORI, XORI},
    {I_Type_Opcode::SRI, SRLI},    {I_Type_Opcode::ORI, ORI},
    {I_Type_Opcode::ANDI, ANDI}};

};  // namespace inst_set

};  // namespace rgemu::risa