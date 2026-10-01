cmake_minimum_required(VERSION 3.20)
project(Runner)

# Standard C++ du module
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Exécutable du Runner : main + Board + Player
add_executable(runner
        src/main.cpp
        src/Board.cpp
        src/Player.cpp
)

# Accès au dossier include/
target_include_directories(runner PRIVATE include)

# Raylib via FetchContent (S04)
include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

# Lier Raylib au Runner
target_link_libraries(runner PRIVATE raylib)
