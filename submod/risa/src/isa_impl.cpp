#include "isa_impl.hpp"
#include <iostream>
#include "op_codes.hpp"

namespace rgemu::risa::interface {

void isa_impl::executeInstruction(OpCodeCell opcode) {
  risa::instruction instr(opcode);
  switch (instr.type) {
    case instruction_type::I_type: {
      auto key = static_cast<I_Type_Opcode>(instr.funct3);
      inst_set::I_Type_Opcode_Functions[key](*hardware, instr);
      break;
    }
    default:
      std::cerr << "Unsupported instruction type: "
                << static_cast<int>(instr.type) << std::endl;
      break;
  }
}

};  // namespace rgemu::risa::interface
