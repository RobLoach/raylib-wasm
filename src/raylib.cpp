#include <emscripten/bind.h>
#include <raylib-cpp.hpp>

#include "./structs.hpp"
#include "./constants.hpp"
#include "./functions.hpp"
#include "./functions-extra.hpp"

using namespace emscripten;

Camera UpdateCameraWrapper(Camera camera) {
    UpdateCamera(&camera);
    return camera;
}

EMSCRIPTEN_BINDINGS(raylib) {
    raylib_structs();
    raylib_constants();
    raylib_functions();
    raylib_functions_extra();

    // Core
    // function("InitWindow", &raylib::InitWindow);
    // function("WindowShouldClose", &WindowShouldClose);
    // function("CloseWindow", &CloseWindow);
    // function("IsWindowReady", &IsWindowReady);
    // function("IsWindowFullscreen", &IsWindowFullscreen);
    // function("IsWindowHidden", &IsWindowHidden);
    // function("IsWindowMinimized", &IsWindowMinimized);
    // function("IsWindowMaximized", &IsWindowMaximized);
    // function("IsWindowFocused", &IsWindowFocused);
    // function("IsWindowResized", &IsWindowResized);
    // function("IsWindowState", &IsWindowState);
    // function("SetWindowState", &SetWindowState);
    // function("ClearWindowState", &ClearWindowState);
    // function("ToggleFullscreen", &ToggleFullscreen);
    // function("MaximizeWindow", &MaximizeWindow);
    // function("MinimizeWindow", &MinimizeWindow);
    // function("RestoreWindow", &RestoreWindow);
    // function("SetWindowIcon", &SetWindowIcon);
    // function("SetWindowPosition", &SetWindowPosition);
    // function("SetWindowMonitor", &SetWindowMonitor);
    // function("SetWindowMinSize", &SetWindowMinSize);
    // function("SetWindowSize", &SetWindowSize);
    // function("GetScreenWidth", &GetScreenWidth);
    // function("GetScreenHeight", &GetScreenHeight);
    // function("GetMonitorCount", &GetMonitorCount);
    // function("GetMonitorPosition", &GetMonitorPosition);
    // function("GetMonitorWidth", &GetMonitorWidth);
    // function("GetMonitorHeight", &GetMonitorHeight);
    // function("GetMonitorPhysicalWidth", &GetMonitorPhysicalWidth);
    // function("GetMonitorPhysicalHeight", &GetMonitorPhysicalHeight);
    // function("GetMonitorRefreshRate", &GetMonitorRefreshRate);
    // function("GetWindowPosition", &GetWindowPosition);
    // function("GetWindowScaleDPI", &GetWindowScaleDPI);
    // function("GetMonitorName", &raylib::GetMonitorName);
    // function("SetClipboardText", &raylib::SetClipboardText);
    // function("GetClipboardText", &raylib::GetClipboardText);
    // function("SetWindowTitle", &raylib::SetWindowTitle);
    // function("ShowCursor", &ShowCursor);
    // function("HideCursor", &HideCursor);
    // function("IsCursorHidden", &IsCursorHidden);
    // function("EnableCursor", &EnableCursor);
    // function("DisableCursor", &DisableCursor);
    // function("IsCursorOnScreen", &IsCursorOnScreen);
    // function("ClearBackground", &ClearBackground);
    // function("BeginDrawing", &BeginDrawing);
    // function("EndDrawing", &EndDrawing);
    // function("BeginMode2D", &BeginMode2D);
    // function("EndMode2D", &EndMode2D);
    // function("BeginMode3D", &BeginMode3D);
    // function("EndMode3D", &EndMode3D);
    // function("BeginTextureMode", &BeginTextureMode);
    // function("EndTextureMode", &EndTextureMode);
    // function("BeginScissorMode", &BeginScissorMode);
    // function("EndScissorMode", &EndScissorMode);
    // function("GetMouseRay", &GetMouseRay);
    // function("GetCameraMatrix", &GetCameraMatrix);
    // function("GetCameraMatrix2D", &GetCameraMatrix2D);
    // function("GetWorldToScreen", &GetWorldToScreen);
    // function("GetWorldToScreenEx", &GetWorldToScreenEx);
    // function("GetWorldToScreen2D", &GetWorldToScreen2D);
    // function("GetScreenToWorld2D", &GetScreenToWorld2D);
    // function("SetTargetFPS", &SetTargetFPS);
    // function("GetFPS", &GetFPS);
    // function("GetFrameTime", &GetFrameTime);
    // function("GetTime", &GetTime);
    // function("SetConfigFlags", &SetConfigFlags);
    // //function("SetTraceLogLevel", &SetTraceLogLevel);
    // //function("SetTraceLogExit", &SetTraceLogExit);
    // //function("SetTraceLogCallback", &SetTraceLogCallback);
    // //function("TraceLog", &TraceLog);
    // function("TakeScreenshot", &raylib::TakeScreenshot);
    // function("GetRandomValue", &GetRandomValue);
    // //function("LoadFileData", &raylib::LoadFileData);
    // //function("UnloadFileData", &UnloadFileData);
    // //function("SaveFileData", &raylib::SaveFileData);
    // function("LoadFileText", &raylib::LoadFileText);
    // //function("UnloadFileText", &UnloadFileText);
    // function("SaveFileText", &raylib::SaveFileText);
    // function("FileExists", &raylib::FileExists);
    // function("DirectoryExists", &raylib::DirectoryExists);
    // function("IsFileExtension", &raylib::IsFileExtension);
    // function("GetFileExtension", &raylib::GetFileExtension);
    // function("GetFileName", &raylib::GetFileName);
    // function("GetFileNameWithoutExt", &raylib::GetFileNameWithoutExt);
    // function("GetDirectoryPath", &raylib::GetDirectoryPath);
    // function("GetPrevDirectoryPath", &raylib::GetPrevDirectoryPath);
    // function("GetWorkingDirectory", &raylib::GetWorkingDirectory);
    // function("GetDirectoryFiles", &raylib::GetDirectoryFiles);
    // function("ClearDirectoryFiles", &ClearDirectoryFiles);
    // function("ChangeDirectory", &raylib::ChangeDirectory);
    // function("IsFileDropped", &IsFileDropped);
    // function("GetDroppedFiles", &raylib::GetDroppedFiles);
    // function("ClearDroppedFiles", &ClearDroppedFiles);
    // function("GetFileModTime", &raylib::GetFileModTime);
    // //function("CompressData", &CompressData);
    // //function("DecompressData", &DecompressData);
    // function("SaveStorageValue", &SaveStorageValue);
    // function("LoadStorageValue", &LoadStorageValue);
    // function("OpenURL", &raylib::OpenURL);
    // function("IsKeyPressed", &IsKeyPressed);
    // function("IsKeyDown", &IsKeyDown);
    // function("IsKeyReleased", &IsKeyReleased);
    // function("IsKeyUp", &IsKeyUp);
    // function("SetExitKey", &SetExitKey);
    // function("GetKeyPressed", &GetKeyPressed);
    // function("GetCharPressed", &GetCharPressed);
    // function("IsGamepadAvailable", &IsGamepadAvailable);
    // //function("IsGamepadName", &raylib::IsGamepadName);
    // //function("GetGamepadName", &raylib::GetGamepadName);
    // function("IsGamepadButtonPressed", &IsGamepadButtonPressed);
    // function("IsGamepadButtonDown", &IsGamepadButtonDown);
    // function("IsGamepadButtonReleased", &IsGamepadButtonReleased);
    // function("IsGamepadButtonUp", &IsGamepadButtonUp);
    // function("GetGamepadButtonPressed", &GetGamepadButtonPressed);
    // function("GetGamepadAxisCount", &GetGamepadAxisCount);
    // function("GetGamepadAxisMovement", &GetGamepadAxisMovement);
    // function("IsMouseButtonPressed", &IsMouseButtonPressed);
    // function("IsMouseButtonDown", &IsMouseButtonDown);
    // function("IsMouseButtonReleased", &IsMouseButtonReleased);
    // function("IsMouseButtonUp", &IsMouseButtonUp);
    // function("GetMouseX", &GetMouseX);
    // function("GetMouseY", &GetMouseY);
    // function("GetMousePosition", &GetMousePosition);
    // function("SetMousePosition", &SetMousePosition);
    // function("SetMouseOffset", &SetMouseOffset);
    // function("SetMouseScale", &SetMouseScale);
    // function("GetMouseWheelMove", &GetMouseWheelMove);
    // function("GetTouchX", &GetTouchX);
    // function("GetTouchY", &GetTouchY);
    // function("SetGesturesEnabled", &SetGesturesEnabled);
    // function("IsGestureDetected", &IsGestureDetected);
    // function("GetGestureDetected", &GetGestureDetected);
    // function("GetGestureHoldDuration", &GetGestureHoldDuration);
    // function("GetGestureDragVector", &GetGestureDragVector);
    // function("GetGestureDragAngle", &GetGestureDragAngle);
    // function("GetGesturePinchVector", &GetGesturePinchVector);
    // function("GetGesturePinchAngle", &GetGesturePinchAngle);
    // function("SetCameraMode", &SetCameraMode);
    // function("UpdateCamera", &UpdateCameraWrapper);
    // function("SetCameraPanControl", &SetCameraPanControl);
    // function("SetCameraAltControl", &SetCameraAltControl);
    // function("SetCameraSmoothZoomControl", &SetCameraSmoothZoomControl);
    // function("SetCameraMoveControls", &SetCameraMoveControls);

    // // Shapes
    // function("DrawPixel", &DrawPixel);
    // function("DrawPixelV", &DrawPixelV);
    // function("DrawLine", &DrawLine);
    // function("DrawLineV", &DrawLineV);
    // function("DrawLineEx", &DrawLineEx);
    // function("DrawLineBezier", &DrawLineBezier);
    // //function("DrawLineStrip", &DrawLineStrip);
    // function("DrawCircle", &DrawCircle);
    // function("DrawCircleSector", &DrawCircleSector);
    // function("DrawCircleSectorLines", &DrawCircleSectorLines);
    // function("DrawCircleGradient", &DrawCircleGradient);
    // function("DrawCircleV", &DrawCircleV);
    // function("DrawCircleLines", &DrawCircleLines);
    // function("DrawEllipse", &DrawEllipse);
    // function("DrawEllipseLines", &DrawEllipseLines);
    // function("DrawRing", &DrawRing);
    // function("DrawRingLines", &DrawRingLines);
    // function("DrawRectangle", &DrawRectangle);
    // function("DrawRectangleV", &DrawRectangleV);
    // function("DrawRectangleRec", &DrawRectangleRec);
    // function("DrawRectanglePro", &DrawRectanglePro);
    // function("DrawRectangleGradientV", &DrawRectangleGradientV);
    // function("DrawRectangleGradientH", &DrawRectangleGradientH);
    // function("DrawRectangleGradientEx", &DrawRectangleGradientEx);
    // function("DrawRectangleLines", &DrawRectangleLines);
    // function("DrawRectangleLinesEx", &DrawRectangleLinesEx);
    // function("DrawRectangleRounded", &DrawRectangleRounded);
    // function("DrawRectangleRoundedLines", &DrawRectangleRoundedLines);
    // function("DrawTriangle", &DrawTriangle);
    // function("DrawTriangleLines", &DrawTriangleLines);
    // // function("DrawTriangleFan", &DrawTriangleFan);
    // // function("DrawTriangleStrip", &DrawTriangleStrip);
    // function("DrawPoly", &DrawPoly);
    // function("DrawPolyLines", &DrawPolyLines);
    // function("CheckCollisionRecs", &CheckCollisionRecs);
    // function("CheckCollisionCircles", &CheckCollisionCircles);
    // function("CheckCollisionCircleRec", &CheckCollisionCircleRec);
    // function("CheckCollisionPointRec", &CheckCollisionPointRec);
    // function("CheckCollisionPointCircle", &CheckCollisionPointCircle);
    // function("CheckCollisionPointTriangle", &CheckCollisionPointTriangle);
    // // function("CheckCollisionLines", &CheckCollisionLines);
    // function("GetCollisionRec", &GetCollisionRec);

    // Textures
    // TODO: Add Textures
}
