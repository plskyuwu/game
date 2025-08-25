#include "window.h"

#include "../../utilities/logger/logger.h"

#ifdef _WIN32
#elif __APPLE__
#elif __linux__
#include "x11_window.h"
#endif


std::unique_ptr<graphics::window::Window> graphics::window::create() {
#ifdef _WIN32
    utilities::logger::global_logger->log(LogLevel::Debug, "Detected Windows");
#elif __APPLE__
    utilities::logger::global_logger->log(LogLevel::Debug, "Detected macOS");
#elif __linux__
    utilities::logger::global_logger->log(LogLevel::Debug, "Detected Linux");
    utilities::logger::global_logger->log(LogLevel::Debug, "Creating a X11 window");
    return std::make_unique<X11Window>();
#endif
    utilities::logger::global_logger->log(LogLevel::Warning, "Detected an unsupported os");
    return nullptr;
}
