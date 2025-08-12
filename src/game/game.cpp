#include "game.h"

#include "../graphics/window/window.h"

Game::Game() {
    window_ = graphics::window::create();
}

void Game::run() const {
    window_->create(1280, 720, "Ejc of linux");
    window_->show();
}
