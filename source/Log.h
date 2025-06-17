#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

#define LOG_LEVEL_TRACE spdlog::level::trace
#define LOG_LEVEL_DEBUG spdlog::level::debug
#define LOG_LEVEL_INFO spdlog::level::info
#define LOG_LEVEL_WARN spdlog::level::warn
#define LOG_LEVEL_ERROR spdlog::level::err
#define LOG_LEVEL_CRITICAL spdlog::level::critical

class Log
{
private:
  static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_interface;

public:
  static std::shared_ptr<spdlog::logger> logger;
  static void setup(spdlog::level::level_enum log_level);
};

#define MSG_TRACE(x, ...) Log::logger->trace(x, __VA_ARGS__);
#define MSG_DEBUG(x, ...) Log::logger->debug(x, __VA_ARGS__);
#define MSG_INFO(x, ...) Log::logger->info(x, __VA_ARGS__);
#define MSG_WARN(x, ...) Log::logger->warn(x, __VA_ARGS__);
#define MSG_ERROR(x, ...) Log::logger->error(x, __VA_ARGS__);
#define MSG_CRITICAL(x, ...) Log::logger->critical(x, __VA_ARGS__);
