const r = @import("raylib-wasm.zig");


export fn Init() void {
    //r.InitWindow(800, 450, "raylib-wasm");
    //r.SetTargetFPS(60);
}

export fn UpdateDrawFrame() void {
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    //r.BeginDrawing();
        //r.ClearBackground(r.RAYWHITE);

        //r.DrawText("Congrats! You created your first raylib-wasm Zig window!", 140, 200, 20, r.LIGHTGRAY);
    //r.EndDrawing();

}

export fn Close() void {
    //r.TraceLog(3, "ABYE!");
}

// // we'll import this from JS-land
// extern fn console_log_ex(message: [*]const u8, length: u8) void;

// // we'll export this to JS-land
// export fn add(a: i32, b: i32) i32 {
//     const log = "happy happy joy joy";
//     console_log_ex(log, log.len);
//     return a + b;
// }
