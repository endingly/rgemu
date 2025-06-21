#pragma once
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace rgemu::risa {
struct RISA_LOG_AUTO {
  RISA_LOG_AUTO() { spdlog::stdout_color_mt("RISA"); }

  ~RISA_LOG_AUTO() { spdlog::drop("RISA"); }
};
};  // namespace rgemu::risa