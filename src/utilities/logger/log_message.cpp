#include "log_message.h"

#include <utility>

namespace utilities::logger {
    LogMessage::LogMessage(const LogLevel log_level, std::string message) {
        log_level_ = log_level;
        message_ = std::move(message);
    }

    std::string LogMessage::as_string() const {
        std::string string;

        switch (log_level_) {
            case LogLevel::Debug:
                string.append("[Debug] ");
                break;
            case LogLevel::Info:
                string.append("[Info] ");
                break;
            case LogLevel::Warning:
                string.append("[Warning] ");
                break;
            case LogLevel::Error:
                string.append("[Error] ");
                break;
        }

        string.append(message_);

        return string;
    }

    LogLevel LogMessage::get_log_level() const {
        return log_level_;
    }

    std::string LogMessage::get_message() {
        return message_;
    }
}
