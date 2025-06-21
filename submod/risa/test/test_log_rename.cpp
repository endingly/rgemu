#include <gtest/gtest.h>
#include <risa/risa_log.hpp>

TEST(RisaLogTest, LogRename) {
  auto log = spdlog::get("RISA");
  log->info("Hello, world!");
}