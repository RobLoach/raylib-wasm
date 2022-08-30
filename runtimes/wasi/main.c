#include "raylib.h"
#include "wasm3.h"
#include "m3_env.h"

#define RUNTIME_SIZE 1024

static m3ApiRawFunction (InitWindowBinding) {
    m3ApiGetArg(int, width);
    m3ApiGetArg(int, height);
    m3ApiGetArgMem(const char *, title);
    InitWindow(width, height, title);
    m3ApiSuccess();
}

static m3ApiRawFunction (BeginDrawingBinding) {
    BeginDrawing();
    m3ApiSuccess();
}

static m3ApiRawFunction (ClearBackgroundExpandedBinding) {
    m3ApiGetArg(int, colorR);
    m3ApiGetArg(int, colorG);
    m3ApiGetArg(int, colorB);
    m3ApiGetArg(int, colorA);
    Color color;
    color.r = colorR;
    color.g = colorG;
    color.b = colorB;
    color.a = colorA;
    ClearBackground(color);
    m3ApiSuccess();
}

static m3ApiRawFunction (DrawTextExpandedBinding) {
    m3ApiGetArgMem(const char *, text);
    m3ApiGetArg(int, posX);
    m3ApiGetArg(int, posY);
    m3ApiGetArg(int, fontSize);
    m3ApiGetArg(int, colorR);
    m3ApiGetArg(int, colorG);
    m3ApiGetArg(int, colorB);
    m3ApiGetArg(int, colorA);
    Color color;
    color.r = colorR;
    color.g = colorG;
    color.b = colorB;
    color.a = colorA;
    DrawText(text, posX, posY, fontSize, color);
    m3ApiSuccess();
}

static m3ApiRawFunction (GetFPSBinding) {
    m3ApiReturnType(int);
    int fps = GetFPS();
    m3ApiReturn(fps);
}

static m3ApiRawFunction (TraceLogBinding) {
    m3ApiGetArg(int, logLevel);
    m3ApiGetArgMem(const char *, text);
    TraceLog(logLevel, text);
    m3ApiSuccess();
}

static m3ApiRawFunction (SetTargetFPSBinding) {
    m3ApiGetArg(int, fps);
    SetTargetFPS(fps);
    m3ApiSuccess();
}

static m3ApiRawFunction (EndDrawingBinding) {
    EndDrawing();
    m3ApiSuccess();
}

static m3ApiRawFunction (CloseWindowBinding) {
    CloseWindow();
    m3ApiSuccess();
}

// all wasm3 functions return same sort of error-pattern, so this wraps that
static void CheckWasm3Error(M3Runtime* runtime, M3Result result) {
  if (result) {
    M3ErrorInfo info;
    m3_GetErrorInfo(runtime, &info);
    TraceLog(LOG_ERROR, "%s - %s", result, info.message);
  }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        TraceLog(LOG_ERROR, "Need an arg");
        return 1;
    }

    // Make sure the file exists.
    const char* filename = argv[1];
    if (!FileExists(filename)) {
        TraceLog(LOG_ERROR, "File not found: %s", filename);
        return 1;
    }

    unsigned int bytesRead;
    unsigned char* fileData = LoadFileData(filename, &bytesRead);
    if (bytesRead == 0) {
        TraceLog(LOG_FATAL, "Could not load file");
        return 1;
    }

    M3Result result = m3Err_none;

    IM3Environment env = m3_NewEnvironment();
    if (!env) {
        TraceLog(LOG_FATAL, "m3_NewEnvironment failed");
        UnloadFileData(fileData);
        return 1;
    }

    IM3Runtime runtime = m3_NewRuntime(env, RUNTIME_SIZE, NULL);
    if (!runtime) {
        TraceLog(LOG_FATAL, "m3_NewRuntime failed");
        UnloadFileData(fileData);
        return 1;
    }

    //TraceLog(LOG_INFO, "ResizeMemory");
    runtime->memory.maxPages = 1;
    ResizeMemory(runtime, 1);

    IM3Module module;
    result = m3_ParseModule(env, &module, fileData, bytesRead);
    UnloadFileData(fileData);
    if (result) {
        TraceLog(LOG_FATAL, "m3_ParseModule: %s", result);
        return 1;
    }

    module->memoryImported = true;
    result = m3_LoadModule(runtime, module);
    if (result) {
        TraceLog(LOG_FATAL, "m3_LoadModule: %s", result);
        return 1;
    }

    // Imports
    m3_LinkRawFunction(module, "env", "InitWindow", "v(iii)", &InitWindowBinding);
    m3_LinkRawFunction(module, "env", "TraceLog", "v(ii)", &TraceLogBinding);
    m3_LinkRawFunction(module, "env", "CloseWindow", "v()", &CloseWindowBinding);
    m3_LinkRawFunction(module, "env", "BeginDrawing", "v()", &BeginDrawingBinding);
    m3_LinkRawFunction(module, "env", "ClearBackgroundExpanded", "v(iiii)", ClearBackgroundExpandedBinding);
    m3_LinkRawFunction(module, "env", "DrawTextExpanded", "v(iiiiiiii)", DrawTextExpandedBinding);
    m3_LinkRawFunction(module, "env", "SetTargetFPS", "v(i)", &SetTargetFPSBinding);
    m3_LinkRawFunction(module, "env", "EndDrawing", "v()", &EndDrawingBinding);
    m3_LinkRawFunction(module, "env", "GetFPS", "i()", &GetFPSBinding);

    M3ErrorInfo error;
    m3_GetErrorInfo(runtime, &error);
    if (error.result) {
        TraceLog(LOG_ERROR, "%s - %s", error.result, error.message);
        return 1;
    }

    M3Function* init;
    M3Function* updateDrawFrame;
    M3Function* close;
    m3_FindFunction(&init, runtime, "Init");
    m3_FindFunction(&updateDrawFrame, runtime, "UpdateDrawFrame");
    m3_FindFunction(&close, runtime, "Close");

    if (init) {
        result = m3_Call(init, 0, NULL);
        if (result) {
            CheckWasm3Error(runtime, result);
        }
    }
    else {
        TraceLog(LOG_WARNING, "No Init() function");
    }

    while (!WindowShouldClose()) {
        if (updateDrawFrame) {
            result = m3_Call(updateDrawFrame, 0, NULL);
            if (result) {
                CheckWasm3Error(runtime, result);
            }
        }
    }

    if (close) {
        result = m3_Call(close, 0, NULL);
        if (result) {
            CheckWasm3Error(runtime, result);
        }
    }
    else {
        TraceLog(LOG_WARNING, "No Close() function");
    }

    // Force it to close if it didn't.
    if (IsWindowReady()) {
        CloseWindow();
    }

    return 0;
}
