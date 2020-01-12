//
// Created by james-laptop on 05/01/2020.
//

#ifndef ILLATE_DEBUG_H
#define ILLATE_DEBUG_H

#include <iostream>

#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/logger.h"

typedef struct IRuntimeException : public std::exception
{
    std::string msg;

    IRuntimeException(std::string msg){
        this->msg = msg;
    }

    const std::string info () const throw ()
    {
        return this->msg;
    }
}IRuntimeException;

// By default debugging is enabled
#ifndef R_DEBUG_ENABLED
    #define R_DEBUG_ENABLED
#endif


#define CRITICAL_RUNTIME_ERROR(...) { \
    throw IRuntimeException(std::string(__VA_ARGS__)); \
}

// Used when during runtime we encounter a critical issue, if the assertion fails then the vm will break
#define R_ASSERT(err, ...) { \
    if(!err) { CRITICAL_RUNTIME_ERROR(std::strcat("Assertion Failed: ", __VA_ARGS__)); } \
}

/**
 * Logging is handled below.
 * Illate uses spd logger because its good and I cba writing my own
 * */

namespace debug{
    class Logger{
    public:
        static std::shared_ptr<spdlog::sinks::stdout_sink_mt> _runtime_sink;
        static std::shared_ptr<spdlog::logger> _runtime_logger;
    };
};

#define R_TRACE(...)    ::debug::Logger::_runtime_logger->trace(__VA_ARGS__)
#define R_INFO(...)     ::debug::Logger::_runtime_logger->info(__VA_ARGS__)
#define R_WARN(...)     ::debug::Logger::_runtime_logger->warn(__VA_ARGS__)
#define R_ERROR(...)    ::debug::Logger::_runtime_logger->error(__VA_ARGS__)
#define R_CRITICAL(...) ::debug::Logger::_runtime_logger->critical(__VA_ARGS__)

#endif //ILLATE_DEBUG_H
