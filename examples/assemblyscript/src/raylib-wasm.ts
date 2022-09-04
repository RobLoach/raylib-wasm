
// Color, 4 components, R8G8B8A8 (32bit)
export class Color {
    r: u8
    g: u8
    b: u8
    a: u8

    constructor(r:u8, g:u8, b:u8, a:u8 = 255) {
        this.r = r
        this.g = g
        this.b = b
        this.a = a
    }
}

export const LIGHTGRAY: Color = new Color(200, 200, 200, 255)   // Light Gray
export const GRAY     : Color = new Color(130, 130, 130, 255)   // Gray
export const DARKGRAY : Color = new Color(80, 80, 80, 255)      // Dark Gray
export const YELLOW   : Color = new Color(253, 249, 0, 255)     // Yellow
export const GOLD     : Color = new Color(255, 203, 0, 255)     // Gold
export const ORANGE   : Color = new Color(255, 161, 0, 255)     // Orange
export const PINK     : Color = new Color(255, 109, 194, 255)   // Pink
export const RED      : Color = new Color(230, 41, 55, 255)     // Red
export const MAROON   : Color = new Color(190, 33, 55, 255)     // Maroon
export const GREEN    : Color = new Color(0, 228, 48, 255)      // Green
export const LIME     : Color = new Color(0, 158, 47, 255)      // Lime
export const DARKGREEN: Color = new Color(0, 117, 44, 255)      // Dark Green
export const SKYBLUE  : Color = new Color(102, 191, 255, 255)   // Sky Blue
export const BLUE     : Color = new Color(0, 121, 241, 255)     // Blue
export const DARKBLUE : Color = new Color(0, 82, 172, 255)      // Dark Blue
export const PURPLE   : Color = new Color(200, 122, 255, 255)   // Purple
export const VIOLET   : Color = new Color(135, 60, 190, 255)    // Violet
export const DARKPURPLE  : Color = new Color(112, 31, 126, 255)    // Dark Purple
export const BEIGE    : Color = new Color(211, 176, 131, 255)   // Beige
export const BROWN    : Color = new Color(127, 106, 79, 255)    // Brown
export const DARKBROWN: Color = new Color(76, 63, 47, 255)      // Dark Brown

export const WHITE    : Color = new Color(255, 255, 255, 255)   // White
export const BLACK    : Color = new Color(0, 0, 0, 255)         // Black
export const BLANK    : Color = new Color(0, 0, 0, 0)           // Blank (Transparent)
export const MAGENTA  : Color = new Color(255, 0, 255, 255)     // Magenta
export const RAYWHITE : Color = new Color(245, 245, 245, 255)   // My own White (raylib logo)

/*

WASM_EXPORT("Init")
void Init();

WASM_EXPORT("UpdateDrawFrame")
void UpdateDrawFrame();

WASM_EXPORT("Close")
void Close();

WASM_IMPORT("InitWindow")
void InitWindow(int width, int height, const char *title);

WASM_IMPORT("BeginDrawing")
void BeginDrawing();

WASM_IMPORT("ClearBackgroundExpanded")
void ClearBackgroundExpanded(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

WASM_IMPORT("DrawTextExpanded")
void DrawTextExpanded(const char *text, int posX, int posY, int fontSize, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

WASM_IMPORT("ClearBackground")
void ClearBackground();

WASM_IMPORT("SetTargetFPS")
void SetTargetFPS(int fps);

WASM_IMPORT("EndDrawing")
void EndDrawing();

WASM_IMPORT("CloseWindow")
void CloseWindow();

WASM_IMPORT("TraceLog")
void TraceLog(int logLevel, const char* text);

// Function wrappers
void ClearBackground(Color color);
void DrawText(const char* text, int posX, int posY, int fontSize, Color color);

#ifdef RAYLIB_WASM_IMPLEMENTATION
#ifndef RAYLIB_WASM_IMPLEMENTATION_ONCE
#define RAYLIB_WASM_IMPLEMENTATION_ONCE

void ClearBackground(Color color) {
    ClearBackgroundExpanded(color.r, color.g, color.b, color.a);
}

void DrawText(const char* text, int posX, int posY, int fontSize, Color color) {
    DrawTextExpanded(text, posX, posY, fontSize, color.r, color.g, color.b, color.a);
}

#endif  // RAYLIB_WASM_IMPLEMENTATION_ONCE
#endif  // RAYLIB_WASM_IMPLEMENTATION

#endif  // RAYLIB_WASM
*/

export const LOG_ALL = 0
export const LOG_TRACE = 1
export const LOG_DEBUG = 2
export const LOG_INFO = 3
export const LOG_WARNING = 4
export const LOG_ERROR = 5
export const LOG_FATAL = 6
export const LOG_NONE = 7

// convert a Color to an i32 (to pass over wasm)
function toColor(color: Color): i32 {
    return ((color.r & 0xFF) << 24) + ((color.g & 0xFF) << 16) + ((color.b) << 8) + (color.a & 0xFF)
}

@external("env", "SetTargetFPS")
export declare function SetTargetFPS(fps: i32) :void

@external("env", "BeginDrawing")
export declare function BeginDrawing() :void

@external("env", "EndDrawing")
export declare function EndDrawing() :void

// these need to be wrapped to convert strings & Colors 

@external("env", "TraceLog")
declare function _TraceLog(logLevel: i32, text: ArrayBuffer) :void
export function TraceLog(logLevel: i32, text: string) :void {
    _TraceLog(logLevel, String.UTF8.encode(text, true))
}

@external("env", "InitWindow")
declare function _InitWindow(width: i32, height: i32, text: ArrayBuffer) :void
export function InitWindow(width: i32, height:i32, title: string) :void {
    _InitWindow(width, height, String.UTF8.encode(title, true))
}

@external("env", "ClearBackground")
declare function _ClearBackground(color: i32) :void
export function ClearBackground(color: Color): void {
    _ClearBackground(toColor(color))
}

@external("env", "DrawText")
declare function _DrawText(text: ArrayBuffer, x: i32, y: i32, fontSize: i32, color: i32) :void
export function DrawText(text: string, x: i32, y: i32, fontSize: i32, color: Color) :void {
    _DrawText(String.UTF8.encode(text, true), x, y, fontSize, toColor(color))
}
