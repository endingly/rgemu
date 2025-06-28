#include "cpu.hpp"

namespace rgemu::hardware {

void cpu_t::initialize() {
  this->registers[0] = 0x00;                   // register x0 hardwired to 0
  this->registers[2] = DRAM_BASE + DRAM_SIZE;  // Set stack pointer
  this->pc           = DRAM_BASE;  // Set program counter to the base address
}

uint64_t cpu_t::read(uint64_t address, bus_write_size_t size) {
  return this->bus.read(address, size);
}

void cpu_t::write(uint64_t address, bus_write_size_t size, uint64_t value) {
  this->bus.write(address, size, value);
}

}  // namespace rgemu::hardware
