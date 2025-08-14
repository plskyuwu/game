cmake_minimum_required(VERSION 4.0)

project(game)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
        src/main.cpp
        src/utilities/logger/logger.cpp
        src/utilities/logger/logger.h
        src/graphics/window/window.cpp
        src/graphics/window/window.h
        src/game/game.cpp
        src/game/game.h)

find_package(OpenGL REQUIRED)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(X11 REQUIRED)
    list(APPEND SOURCES
            src/graphics/window/x11_window.cpp
            src/graphics/window/x11_window.h)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    find_library(COCOA_LIBRARY Cocoa)
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL X11 GLX)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL ${COCOA_LIBRARY})
endif ()