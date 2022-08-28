#include "raylib-wasm.h"

void Init() {
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(800, 450, "raylib-wasm [core] example - basic window");
    SetTargetFPS(60);
    TraceLog(LOG_INFO, "Hello!!!!!!! Init()");
}

void UpdateDrawFrame() {
    TraceLog(LOG_INFO, "HOW ARE YOU???");
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
}

void Close() {
    TraceLog(LOG_INFO, "Close?");
    CloseWindow();
}
