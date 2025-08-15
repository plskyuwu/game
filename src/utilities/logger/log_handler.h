#pragma once

#include "log_level.h"
#include "log_message.h"

namespace utilities::logger {
    class LogHandler {
    public:
        virtual ~LogHandler() = default;

        virtual void log(LogMessage log_message) = 0;

        virtual LogLevel get_log_level() = 0;

        virtual void set_log_level(LogLevel log_level) = 0;
    };
}
