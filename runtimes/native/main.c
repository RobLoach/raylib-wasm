#include "raylib.h"
#include "wasm3.h"
#include "m3_env.h"

static m3ApiRawFunction (InitWindowBinding) {
    m3ApiGetArg(int, width);
    m3ApiGetArg(int, height);
    m3ApiGetArg(const char *, title);
    InitWindow(width, height, title);
    m3ApiSuccess();
}

static m3ApiRawFunction (BeginDrawingBinding) {
    BeginDrawing();
    m3ApiSuccess();
}

static m3ApiRawFunction (ClearBackgroundBinding) {
    m3ApiGetArg(Color, color);
    ClearBackground(color);
    m3ApiSuccess();
}

static m3ApiRawFunction (DrawTextBinding) {
    m3ApiGetArg(const char *, text);
    m3ApiGetArg(int, posX);
    m3ApiGetArg(int, posY);
    m3ApiGetArg(int, fontSize);
    m3ApiGetArg(Color, color);
    DrawText(text, posX, posY, fontSize, color);
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

    M3Result result = m3Err_none;

    TraceLog(LOG_INFO, "m3_NewEnvironment");
    IM3Environment env = m3_NewEnvironment ();
    if (!env) TraceLog(LOG_FATAL, "m3_NewEnvironment failed");

    TraceLog(LOG_INFO, "m3_NewRuntime");
    IM3Runtime runtime = m3_NewRuntime (env, 64 * 1024, NULL);
    if (!runtime) TraceLog(LOG_FATAL, "m3_NewRuntime failed");

    TraceLog(LOG_INFO, "ResizeMemory");
    runtime->memory.maxPages = 1;
    ResizeMemory(runtime, 1);

    TraceLog(LOG_INFO, "m3_ParseModule");
    IM3Module module;
    result = m3_ParseModule (env, &module, fileData, bytesRead);
    if (result) TraceLog(LOG_FATAL, "m3_ParseModule: %s", result);

    TraceLog(LOG_INFO, "m3_LoadModule");
    module->memoryImported = true;
    TraceLog(LOG_INFO, "m3_LoadModule2");
    result = m3_LoadModule (runtime, module);
    TraceLog(LOG_INFO, "m3_LoadModule3");
    if (result) TraceLog(LOG_FATAL, "m3_LoadModule: %s", result);

    TraceLog(LOG_INFO, "m3_LinkRawFunction");
    m3_LinkRawFunction(module, "env", "InitWindow", "v(iii)", InitWindowBinding);
    m3_LinkRawFunction(module, "env", "BeginDrawing", "v()", InitWindowBinding);
    m3_LinkRawFunction(module, "env", "ClearBackground", "v(i)", InitWindowBinding);
    m3_LinkRawFunction(module, "env", "DrawText", "v(iiiii)", InitWindowBinding);
    m3_LinkRawFunction(module, "env", "SetTargetFPS", "v(i)", InitWindowBinding);
    m3_LinkRawFunction(module, "env", "EndDrawing", "v()", InitWindowBinding);
    TraceLog(LOG_INFO, "m3_FindFunction");

    IM3Function f;
    result = m3_FindFunction (&f, runtime, "Init");
    TraceLog(LOG_INFO, "FDSAOFASDFASD");

    if (result) {
        TraceLog(LOG_WARNING, "Init() not found: %s", result);
    }
    else {
        result = m3_CallV(f);
        if (result) {
            TraceLog(LOG_FATAL, "Call: %s", result);
        }
    }

    TraceLog(LOG_INFO, "m3_FindFunction");

    result = m3_FindFunction (&f, runtime, "UpdateDrawFrame");
    if (result) {
        TraceLog(LOG_WARNING, "UpdateDrawFrame() not found: %s", result);
        CloseWindow();
    }
    else {
        while (!WindowShouldClose()) {
            result = m3_CallV(f);
            if (result) {
                TraceLog(LOG_FATAL, "Call: %s", result);
                CloseWindow();
            }
        }
    }

    // result = m3_CallV (f, 40);

    // if (result) TraceLog(LOG_FATAL, "Call: %s", result);

    // uint32_t value = 0;
    // result = m3_GetResultsV (f, &value);
    // if (result) TraceLog(LOG_FATAL, "m3_GetResults: %s", result);

    // printf("Result: %d\n", value);

    // TraceLog(LOG_INFO, "Passed: %s", argv[1]);
    return 0;
}
