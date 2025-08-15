#include <vector>

#include "logger.h"

namespace utilities::logger {
    Logger::Logger() {
        log_handlers_ = new std::vector<LogHandler *>;
    }

    Logger::Logger(const std::initializer_list<LogHandler *> log_handlers) {
        log_handlers_ = new std::vector<LogHandler *>;

        for (auto *log_handler: log_handlers) {
            add_log_handler(log_handler);
        }
    }

    Logger::~Logger() {
        free(log_handlers_);
    }

    void Logger::log(const LogLevel log_level, const std::string &message) const {
        log(LogMessage(log_level, message));
    }

    void Logger::log(const LogMessage &log_message) const {
        for (auto *log_handler: *log_handlers_) {
            if (log_handler->get_log_level() <= log_message.get_log_level())
                log_handler->log(log_message);
        }
    }

    void Logger::add_log_handler(LogHandler *log_handler) const {
        log_handlers_->push_back(log_handler);
    }
}
