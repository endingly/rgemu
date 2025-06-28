#include "isa_impl.hpp"
#include "op_codes.hpp"

namespace rgemu::risa::interface {

void isa_impl::executeInstruction(OpCodeCell opcode) {
  risa::instruction instr(opcode);
  switch (instr.type) {
    case instruction_type::I_type:
      auto key = static_cast<I_Type_Opcode>(instr.funct3);
      inst_set::I_Type_Opcode_Functions[key](*hardware, instr);
      break;
    default:
      break;
  }
}

};  // namespace rgemu::risa::interface
