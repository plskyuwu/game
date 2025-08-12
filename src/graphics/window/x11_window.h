#pragma once
#include <GL/glx.h>

#include "window.h"

namespace graphics::window {
    class X11Window final : public Window {
    public:
        ~X11Window() override;

        void create() override;

        void create(std::string title) override;

        void create(u_int32_t width, u_int32_t height) override;

        void create(u_int32_t width, u_int32_t height, std::string title) override;

        void show() override;

        void destroy() override;

    private:
        Display *display_ = nullptr;
        ::Window window_ = 0;
        GLXContext glx_context_ = nullptr;
        bool running_ = false;
    };
}
