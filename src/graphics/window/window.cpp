#include "window.h"

#ifdef _WIN32
#elif __APPLE__
#elif __linux__
#include "x11_window.h"
#endif


std::unique_ptr<graphics::window::Window> graphics::window::create() {
#ifdef _WIN32
#elif __APPLE__
#elif __linux__
    return std::make_unique<X11Window>();
#else
    return nullptr;
#endif
}
