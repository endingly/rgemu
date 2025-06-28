#include "bus.hpp"

namespace rgemu::hardware {

uint64_t bus_t::read(uint64_t         address,
                     bus_write_size_t size = bus_write_size_t::BYTE) {
  return this->dram.read(address, (dram_write_size_t)size);
}

void bus_t::write(uint64_t address, bus_write_size_t size, uint64_t value) {
  this->dram.write(address, (dram_write_size_t)size, value);
}

}  // namespace rgemu::hardware
