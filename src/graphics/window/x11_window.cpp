#include "x11_window.h"

#include <iostream>

#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

namespace graphics::window {
    X11Window::~X11Window() {
        destroy();
    }

    void X11Window::create() {
        create(800, 600, "Game");
    }

    void X11Window::create(const std::string title) {
        create(800, 600, title);
    }

    void X11Window::create(const u_int32_t width, const u_int32_t height) {
        create(width, height, "Game");
    }

    void X11Window::create(const u_int32_t width, const u_int32_t height, const std::string title) {
        display_ = XOpenDisplay(nullptr);

        if (!display_) {
            std::cerr << "Failed to open X display\n";
            exit(1);
        }

        int glx_attributes[] = {
            GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None
        };

        XVisualInfo *visual_info = glXChooseVisual(display_, 0, glx_attributes);

        if (!visual_info) {
            std::cerr << "No appropriate visual found\n";
            exit(1);
        }

        const Colormap colormap = XCreateColormap(
            display_,
            RootWindow(display_, visual_info->screen),
            visual_info->visual,
            AllocNone);

        XSetWindowAttributes set_window_attributes;
        set_window_attributes.colormap = colormap;
        set_window_attributes.event_mask = ExposureMask | KeyPressMask;

        window_ = XCreateWindow(
            display_,
            RootWindow(display_, visual_info->screen),
            0, 0, // Position
            width, height,
            0, // Border width (does nothing 💀)
            visual_info->depth,
            InputOutput,
            visual_info->visual,
            CWColormap | CWEventMask,
            &set_window_attributes);

        XStoreName(display_, window_, title.c_str());

        glx_context_ = glXCreateContext(
            display_, visual_info, nullptr, GL_TRUE);
    }

    void X11Window::show() {
        XMapWindow(display_, window_);

        glXMakeCurrent(display_, window_, glx_context_);

        glClearColor(1.0, 1.0, 1.0, 1.0);

        running_ = true;

        while (true) {
            while (XPending(display_)) {
                XEvent x_event;
                XNextEvent(display_, &x_event);
                if (x_event.type == KeyPress) {
                    running_ = false;
                    break;
                }
            }

            if (!running_) break;

            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.0, 1.0);
            glVertex2f(-0.5, -0.5);
            glColor3f(0.5, 0.0, 0.5);
            glVertex2f(0.5, -0.5);
            glColor3f(0.0, 0.0, 0.0);
            glVertex2f(0.5, 0.5);
            glEnd();
            glXSwapBuffers(display_, window_);
        }
    }

    void X11Window::destroy() {
        glXMakeCurrent(display_, None, nullptr);
        glXDestroyContext(display_, glx_context_);
        XDestroyWindow(display_, window_);
        XCloseDisplay(display_);
    }
}
