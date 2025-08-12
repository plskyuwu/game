cmake_minimum_required(VERSION 4.0)

project(game)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/utilities/logger/logger.cpp
        src/utilities/logger/logger.h
        src/graphics/window/window.cpp
        src/graphics/window/window.h
        src/graphics/window/x11_window.cpp
        src/graphics/window/x11_window.h
        src/game/game.cpp
        src/game/game.h)


target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL X11 GLX)