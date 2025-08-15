#pragma once

#include "log_handler.h"

namespace utilities::logger {
    class TerminalLogHandler final : public LogHandler {
    public:
        explicit TerminalLogHandler(LogLevel log_level);

        ~TerminalLogHandler() override;

        void log(LogMessage log_message) override;

        LogLevel get_log_level() override;

        void set_log_level(LogLevel log_level) override;

    private:
        LogLevel log_level_;
    };
}
