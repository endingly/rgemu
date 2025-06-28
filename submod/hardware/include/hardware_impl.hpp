#pragma once
#include <core/abstraction.hpp>
#include <memory>
#include "cpu.hpp"

namespace rgemu::hardware::interface {

std::unique_ptr<core::IHardwareOperations<cpu_t::RegType>> createHardware();

class hardware_impl : public core::IHardwareOperations<cpu_t::RegType> {

 private:
  cpu_t m_cpu;

 public:
  using RegType = cpu_t::RegType;
  // IHardwareOperations interface
  RegType readRegister(uint8_t reg) override;
  void    writeRegister(uint8_t reg, RegType value) override;
  RegType loadMemory(uint32_t addr) override;
  void    storeMemory(uint32_t addr, RegType value) override;

  ~hardware_impl() override = default;
  hardware_impl()           = default;
};

};  // namespace rgemu::hardware::interface