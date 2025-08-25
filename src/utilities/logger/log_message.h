#pragma once
#include <string>

#include "log_level.h"

namespace utilities::logger {
    // TODO: Add occurrence
    class LogMessage {
    public:
        LogMessage(LogLevel log_level, std::string message);

        std::string as_string() const;

        LogLevel get_log_level() const;

        std::string get_message();

    private:
        LogLevel log_level_;
        std::string message_;
    };
}
