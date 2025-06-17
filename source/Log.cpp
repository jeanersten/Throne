#include "Log.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Log::m_console_interface{ std::make_shared<spdlog::sinks::stdout_color_sink_mt>() };
std::shared_ptr<spdlog::logger> Log::logger{ std::make_shared<spdlog::logger>("THRONE") };

void Log::setup(spdlog::level::level_enum log_level)
{
  logger->sinks().push_back(m_console_interface);
  logger->set_level(log_level);
}
