pub const Color = packed struct {
    r: u8,
    g: u8,
    b: u8,
    a: u8 = 255,
};


// Some Basic Colors
// NOTE: Custom raylib color palette for amazing visuals on WHITE background
pub const LIGHTGRAY = Color{.r=200, .g=200, .b=200 };  // Light Gray
pub const GRAY      = Color{.r=130, .g=130, .b=130 };  // Gray
pub const DARKGRAY  = Color{.r=80, .g=80, .b=80 };     // Dark Gray
pub const YELLOW    = Color{.r=253, .g=249, .b=0 };    // Yellow
pub const GOLD      = Color{.r=255, .g=203, .b=0 };    // Gold
pub const ORANGE    = Color{.r=255, .g=161, .b=0 };    // Orange
pub const PINK      = Color{.r=255, .g=109, .b=194 };  // Pink
pub const RED       = Color{.r=230, .g=41, .b=55 };    // Red
pub const MAROON    = Color{.r=190, .g=33, .b=55 };    // Maroon
pub const GREEN     = Color{.r=0, .g=228, .b=48 };     // Green
pub const LIME      = Color{.r=0, .g=158, .b=47 };     // Lime
pub const DARKGREEN = Color{.r=0, .g=117, .b=44 };     // Dark Green
pub const SKYBLUE   = Color{.r=102, .g=191, .b=255 }; // Sky Blue
pub const BLUE      = Color{.r=0, .g=121, .b=241 };    // Blue
pub const DARKBLUE  = Color{.r=0, .g=82, .b=172 };     // Dark Blue
pub const PURPLE    = Color{.r=200, .g=122, .b=255 };  // Purple
pub const VIOLET    = Color{.r=135, .g=60, .b=190 };   // Violet
pub const DARKPURPLE= Color{.r=112, .g=31, .b=126 };   // Dark Purple
pub const BEIGE     = Color{.r=211, .g=176, .b=131 };  // Beige
pub const BROWN     = Color{.r=127, .g=106, .b=79 };   // Brown
pub const DARKBROWN = Color{.r=76, .g=63, .b=47 };     // Dark Brown
pub const WHITE     = Color{.r=255, .g=255, .b=255 }; // White
pub const BLACK     = Color{.r=0, .g=0, .b=0 };        // Black
pub const BLANK     = Color{.r=0, .g=0, .b=0, .a=0 };          // Blank (Transparent)
pub const MAGENTA   = Color{.r=255, .g=0, .b=255 };   // Magenta
pub const RAYWHITE  = Color{.r=245, .g=245, .b=245 };  // My own White (raylib logo)


// Trace log level
// NOTE: Organized by priority level
// pub enum TraceLogLevel {
//     LOG_ALL = 0,        // Display all logs
//     LOG_TRACE,          // Trace logging, intended for internal use only
//     LOG_DEBUG,          // Debug logging, used for internal debugging, it should be disabled on release builds
//     LOG_INFO,           // Info logging, used for program execution info
//     LOG_WARNING,        // Warning logging, used on recoverable failures
//     LOG_ERROR,          // Error logging, used on unrecoverable failures
//     LOG_FATAL,          // Fatal logging, used to abort program: exit(EXIT_FAILURE)
//     LOG_NONE,            // Disable logging
// };


//pub extern fn InitWindow(width: i32, height: i32, title:[*]const u8) void;

pub extern fn BeginDrawing() void;

pub extern fn ClearBackgroundExpanded(r: i32, g: i32, b: i32, a: i32) void;

//pub extern fn DrawTextExpanded(text:[]const u8, posX: i32, posY: i32, fontSize: i32, r: i32, g: i32, b: i32, a: i32) void;

pub extern fn SetTargetFPS(fps:i32) void;

pub extern fn EndDrawing() void;

pub extern fn CloseWindow() void;

//pub extern fn TraceLog(logLevel:i32, text:[*]const u8) void;

pub fn ClearBackground(color:Color) void {
ClearBackgroundExpanded(color.r, color.g, color.b, color.a);
}

// pub fn DrawText(text:[]const u8, posX:i32, posY:i32, fontSize:i32, color:Color) void {
//     //DrawTextExpanded(text, posX, posY, fontSize, color.r, color.g, color.b, color.a);
// }
