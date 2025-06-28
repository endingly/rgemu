#include "op_codes.hpp"

namespace rgemu::risa::inst_set {

using RegType = rgemu::risa::interface::isa_impl::RegType;

void ADDI(HardwareType& hardware, instruction& inst) {
  RegType imm = hardware.readRegister(inst.rs1) + (int64_t)inst.imm;
  hardware.writeRegister(inst.rd, imm);
}

void SLTI(HardwareType& hardware, instruction& inst) {
  RegType result = static_cast<int64_t>(hardware.readRegister(inst.rs1)) <
                           static_cast<int64_t>(inst.imm)
                       ? 1
                       : 0;
  hardware.writeRegister(inst.rd, result);
}

void SLTIU(HardwareType& hardware, instruction& inst) {
  RegType result = static_cast<uint64_t>(hardware.readRegister(inst.rs1)) <
                           static_cast<uint64_t>(inst.imm)
                       ? 1
                       : 0;
  hardware.writeRegister(inst.rd, result);
}

void XORI(HardwareType& hardware, instruction& inst) {
  RegType result = hardware.readRegister(inst.rs1) ^ inst.imm;
  hardware.writeRegister(inst.rd, result);
}

void ORI(HardwareType& hardware, instruction& inst) {
  RegType result = hardware.readRegister(inst.rs1) | inst.imm;
  hardware.writeRegister(inst.rd, result);
}

void ANDI(HardwareType& hardware, instruction& inst) {
  RegType result = hardware.readRegister(inst.rs1) & inst.imm;
  hardware.writeRegister(inst.rd, result);
}

void SLLI(HardwareType& hardware, instruction& inst) {
  RegType result = hardware.readRegister(inst.rs1) << inst.shamt;
  hardware.writeRegister(inst.rd, result);
}

void SRLI(HardwareType& hardware, instruction& inst) {
  RegType result = hardware.readRegister(inst.rs1) >> inst.shamt;
  hardware.writeRegister(inst.rd, result);
}

void SRAI(HardwareType& hardware, instruction& inst) {
  // Arithmetic right shift
  RegType result =
      static_cast<int64_t>(hardware.readRegister(inst.rs1)) >> inst.shamt;
  hardware.writeRegister(inst.rd, result);
}

};  // namespace rgemu::risa::inst_set
