#pragma once
#include <string>
#include <vector>

#include "log_handler.h"
#include "log_level.h"
#include "terminal_log_handler.h"

namespace utilities::logger {
    class Logger {
    public:
        Logger();

        Logger(std::initializer_list<LogHandler *> log_handlers);

        ~Logger();

        void log(LogLevel log_level, const std::string &message) const;

        void log(const LogMessage &log_message) const;

        void add_log_handler(LogHandler *log_handler) const;

    private:
        std::vector<LogHandler *> *log_handlers_;
    };

    inline auto global_logger = new Logger({new TerminalLogHandler(LogLevel::Debug)});
}
