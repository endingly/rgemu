#include "hardware_impl.hpp"

namespace rgemu::hardware::interface {

std::unique_ptr<core::IHardwareOperations<cpu_t::RegType>> createHardware() {
  return std::make_unique<hardware_impl>();
}

using RegType = hardware_impl::RegType;

RegType hardware_impl::readRegister(uint8_t reg) {
  return m_cpu.registers[reg % m_cpu.RegNum];
}

void hardware_impl::writeRegister(uint8_t reg, RegType value) {
  m_cpu.registers[reg % m_cpu.RegNum] = value;
}

RegType hardware_impl::loadMemory(uint32_t addr) {
  RegType value = m_cpu.bus.read(addr, bus_write_size_t::QWORD);
  return value;
}

void hardware_impl::storeMemory(uint32_t addr, RegType value) {
  m_cpu.bus.write(addr, bus_write_size_t::QWORD, value);
}

};  // namespace rgemu::hardware::interface
