cmake_minimum_required(VERSION 3.11)
project(raylib-wasm
    DESCRIPTION "raylib-wasm: WebAssembly for raylib"
    HOMEPAGE_URL "https://github.com/robloach/raylib-wasm"
    VERSION 4.5.0
    LANGUAGES C
)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
        FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# wasm3
find_package(wasm3 QUIET)
if (NOT wasm3_FOUND)
    include(FetchContent)
        FetchContent_Declare(
        wasm3
        GIT_REPOSITORY https://github.com/wasm3/wasm3.git
        GIT_TAG v0.5.0
    )
    FetchContent_GetProperties(wasm3)
    if (NOT wasm3_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(wasm3)
        add_subdirectory(${wasm3_SOURCE_DIR} ${wasm3_BINARY_DIR})
    endif()
endif()

# raylib-wasm
add_executable(raylib-wasm
    main.c
)

target_link_libraries(raylib-wasm PUBLIC
    raylib
    m3
)
