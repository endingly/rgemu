#include <gtest/gtest.h>
#include <risa/risa_log.hpp>

TEST(RisaLogTest, Log) {
  auto logger = spdlog::get("RISA");
  logger->info("Hello, world!");
}