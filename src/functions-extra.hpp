#ifndef RAYLIB_FUNCTIONS_EXTRA
#define RAYLIB_FUNCTIONS_EXTRA

#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <raylib-cpp.hpp>

using namespace emscripten;


Camera UpdateCameraWrapper(Camera camera) {
    UpdateCamera(&camera);
    return camera;
}

void TraceLogWrapper(int logLevel, const std::string& text) {
    int emscriptenLog = EM_LOG_CONSOLE;
    switch (logLevel) {
        case LOG_ALL:
            emscriptenLog = EM_LOG_CONSOLE;
            break;
        case LOG_TRACE:
        case LOG_DEBUG:
            emscriptenLog = EM_LOG_DEBUG;
            break;
        case LOG_INFO:
            emscriptenLog = EM_LOG_INFO;
            break;
        case LOG_WARNING:
            emscriptenLog = EM_LOG_WARN;
            break;
        case LOG_ERROR:
            emscriptenLog = EM_LOG_ERROR;
            break;
    }
    emscripten_log(emscriptenLog, text.c_str());
}

void raylib_functions_extra() {
    function("TraceLog", &TraceLogWrapper);
    function("UpdateCamera", &UpdateCameraWrapper);
}

#endif
