#pragma once

#include <memory>
#include <string>

namespace graphics::window {
    class Window {
    public:
        virtual ~Window() = default;

        virtual void create() = 0;

        virtual void create(std::string title) = 0;

        virtual void create(u_int32_t width, u_int32_t height) = 0;

        virtual void create(u_int32_t width, u_int32_t height, std::string title) = 0;

        virtual void destroy() = 0;
    };

    std::unique_ptr<Window> create();
}
