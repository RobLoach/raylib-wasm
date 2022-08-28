#define RAYLIB_WASM_IMPLEMENTATION
#include "raylib-wasm.h"

void Init() {
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(800, 450, "raylib-wasm [core] example - basic window");
    SetTargetFPS(60);
}

void UpdateDrawFrame() {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawText("Congrats! You created your first raylib-cpp window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------

    // if (WindowShouldClose()) {
    //     CloseWindow();
    // }
}

void Close() {
    CloseWindow();
}
