//
// Created by james-laptop on 05/01/2020.
//

#ifndef ILLATE_DEBUG_H
#define ILLATE_DEBUG_H

#include <iostream>

#include "spdlog/spdlog.h"

// By default debugging is enabled
#ifndef R_DEBUG_ENABLED
    #define R_DEBUG_ENABLED
#endif


#define CRITICAL_RUNTIME_ERROR(...) {std::cout << "Runtime Error: " << __VA_ARGS__ << std::endl;}

// Used when during runtime we encounter a critical issue, if the assertion fails then the vm will break
#define R_ASSERT(err, ...) { \
    if(!err) { CRITICAL_RUNTIME_ERROR("Assertion Failed: " << __VA_ARGS__); } \
}
#define R_DEBUG(...) {std::cout << "Runtime Debug: " << __VA_ARGS__ << std::endl;}

/**
 * Logging is handled below.
 * Illate uses spd logger because its good and I cba writing my own
 * */

namespace debug{
    class Logger{
    public:
        std::shared_ptr<spdlog::logger> get_runtime_logger();
    private:
    };
};

// Core log macros
#define R_CORE_TRACE(...)    ::debug::Logger::get_runtime_logger()->trace(__VA_ARGS__)
#define R_CORE_INFO(...)     ::debug::Logger::get_runtime_logger()->info(__VA_ARGS__)
#define R_CORE_WARN(...)     ::debug::Logger::get_runtime_logger()->warn(__VA_ARGS__)
#define R_CORE_ERROR(...)    ::debug::Logger::get_runtime_logger()->error(__VA_ARGS__)
#define R_CORE_CRITICAL(...) ::debug::Logger::get_runtime_logger()->critical(__VA_ARGS__)

#endif //ILLATE_DEBUG_H
