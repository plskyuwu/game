#include "game.h"

#include "../graphics/window/window.h"
#include "../utilities/logger/logger.h"

Game::Game() {
    window_ = graphics::window::create();
    if (!window_) {
        utilities::logger::global_logger->log(LogLevel::Error, "Failed to create a window");
    }
}

void Game::run() const {
    utilities::logger::global_logger->log(LogLevel::Debug, "Running game");

    if (window_) {
        utilities::logger::global_logger->log(LogLevel::Debug, "Creating a window");
        window_->create(1280, 720, "Ejc of linux");
        utilities::logger::global_logger->log(LogLevel::Debug, "Showing a window");
        window_->show();
    } else {
        utilities::logger::global_logger->log(LogLevel::Error, "Unsupported os");
    }

    utilities::logger::global_logger->log(LogLevel::Debug, "Stopping game");
}
