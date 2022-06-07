#include <emscripten/bind.h>
#include <raylib-cpp.hpp>

#include "./structs.hpp"
#include "./constants.hpp"
#include "./functions.hpp"
#include "./functions-wrappers.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(raylib) {
    raylib_structs();
    raylib_constants();
    raylib_functions();
    raylib_functions_wrappers();
}
