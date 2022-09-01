const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const mode = b.standardReleaseOptions();
    const lib = b.addSharedLibrary("raylib-wasm-zig", "src/main.zig", .unversioned);

    lib.setBuildMode(mode);
    lib.setTarget(.{
        .cpu_arch = .wasm32,
        .os_tag = .freestanding
    });

    lib.import_memory = true;
    lib.initial_memory = 65536;
    lib.max_memory = 65536;
    lib.stack_size = 14752;

    //lib.setOutputDir("zig-cache");
    b.default_step.dependOn(&lib.step);

    lib.install();
}
