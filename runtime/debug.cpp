//
// Created by james on 08/01/2020.
//

#include "debug.h"

std::shared_ptr<spdlog::sinks::stdout_sink_mt> debug::Logger::_runtime_sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
std::shared_ptr<spdlog::logger> debug::Logger::_runtime_logger = std::make_shared<spdlog::logger>("_runtime_logger", debug::Logger::_runtime_sink);