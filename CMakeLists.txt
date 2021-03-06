cmake_minimum_required(VERSION 3.16.3)

project(raylib-wasm VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PLATFORM Web)

find_package(raylib 4.0.0 QUIET EXACT)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 4.0.0
  )
  FetchContent_MakeAvailable(raylib)
endif()

find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG v4.1.0
  )
  FetchContent_MakeAvailable(raylib_cpp)
endif()

add_executable(raylib-wasm
    src/raylib.cpp
)

target_link_libraries(raylib-wasm PUBLIC raylib raylib_cpp)

set_target_properties(raylib-wasm PROPERTIES
    OUTPUT_NAME "raylib"
    LINK_FLAGS "\
        -s ENVIRONMENT=web,webview,node \
        -s ASYNCIFY \
        -s EXPORT_NAME=raylib \
        -s MODULARIZE=1 \
        -s USE_GLFW=3 \
        -s DEMANGLE_SUPPORT=1 \
        --bind"
)
