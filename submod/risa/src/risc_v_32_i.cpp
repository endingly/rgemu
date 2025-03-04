#include "risc_v_32_i.hpp"
#include "risc_v_common.hpp"

namespace rgemu::risa {

void U_lui(const uint32_t& instr) {
  auto r_s               = *reinterpret_cast<RV32I_U_Instruction*>(instr);
  Register32_vec[r_s.rd] = r_s.imm;
}

};  // namespace rgemu::risa
