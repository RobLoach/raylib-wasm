import {
    TraceLog,
    InitWindow,
    SetTargetFPS,
    BeginDrawing,
    ClearBackground,
    DrawText,
    EndDrawing,
    LOG_INFO,
    RAYWHITE,
    LIGHTGRAY
} from "./raylib-wasm"

export function Init() : void {
    InitWindow(800, 450, "raylib-wasm")
    SetTargetFPS(60)
}

export function UpdateDrawFrame() : void {
    BeginDrawing()
        ClearBackground(RAYWHITE)
        DrawText("Congrats! You created your first raylib-wasm C window!", 140, 200, 20, LIGHTGRAY)
    EndDrawing()
}

export function Close() : void {
    TraceLog(LOG_INFO, "BYE!")
}
