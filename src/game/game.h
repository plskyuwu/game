#pragma once
#include "../graphics/window/window.h"

class Game {
public:
    Game();
    void run() const;
private:
    std::unique_ptr<graphics::window::Window> window_;
};
