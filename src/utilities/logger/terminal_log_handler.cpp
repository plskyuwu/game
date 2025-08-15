#include "terminal_log_handler.h"

#include <iostream>

namespace utilities::logger {
    TerminalLogHandler::TerminalLogHandler(const LogLevel log_level) {
        log_level_ = log_level;
    }

    TerminalLogHandler::~TerminalLogHandler() = default;

    void TerminalLogHandler::log(const LogMessage log_message) {
        std::cout << log_message.as_string() << "\n";
    }

    LogLevel TerminalLogHandler::get_log_level() {
        return log_level_;
    }

    void TerminalLogHandler::set_log_level(const LogLevel log_level) {
        log_level_ = log_level;
    }
}
