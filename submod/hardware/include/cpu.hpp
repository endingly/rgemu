#pragma once
#include <unordered_map>
#include "bus.hpp"

namespace rgemu::hardware {

struct cpu_t {

  using RegType                  = uint64_t;
  using OpcodeLength             = uint32_t;
  constexpr static size_t RegNum = 32;

  RegType pc;                 // Program Counter
  RegType registers[RegNum];  // Assuming a simple register file with 32 registers.
  bus_t   bus;

  void         initialize();
  OpcodeLength fetch_instruction(uint64_t address);
  void         execute_instruction(OpcodeLength instruction);
  void         dump_registers();

 private:
  RegType read(uint64_t address, bus_write_size_t size);
  void    write(uint64_t address, bus_write_size_t size, RegType value);
};

}  // namespace rgemu::hardware