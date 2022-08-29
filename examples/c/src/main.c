#define RAYLIB_WASM_IMPLEMENTATION
#include "raylib-wasm.h"

void Init() {
    InitWindow(800, 450, "raylib-wasm");
    SetTargetFPS(60);
}

void UpdateDrawFrame() {
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first raylib-wasm window!", 150, 200, 20, LIGHTGRAY);
    EndDrawing();
}

void Close() {
    // Nothing.
}
