import * as r from "./raylib-wasm"

export function Init() : void {
    r.TraceLog(r.LOG_INFO, "Hello World!")
}

export function UpdateDrawFrame() : void {
    r.TraceLog(r.LOG_INFO, "Update Draw")
}

export function Close() : void {
    r.TraceLog(r.LOG_INFO, "BYE!")
}
