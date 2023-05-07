const std = @import("std");

pub fn create_cimgui(b: *std.Build, target: std.zig.CrossTarget, optimize: std.builtin.OptimizeMode) !*std.Build.CompileStep {
    var c_flags = std.ArrayList([]const u8).init(b.allocator);

    const cimgui = b.addStaticLibrary(.{
        .name = "cimgui",
        .target = target,
        .optimize = optimize,
    });

    if (target.getOsTag() == .windows) {
        cimgui.linkSystemLibrary("imm32");
    } else if (target.getOsTag() == .linux) {
        try c_flags.append("-fPIC");
    }

    cimgui.addIncludePath(root_path ++ "../wgpu-native/ffi");
    cimgui.addIncludePath(root_path ++ "imgui/");

    cimgui.addCSourceFiles(&.{root_path ++ "cimgui.cpp"}, c_flags.items);
    cimgui.addCSourceFiles(&.{
        root_path ++ "imgui/imgui.cpp",
        root_path ++ "imgui/imgui_draw.cpp",
        root_path ++ "imgui/imgui_tables.cpp",
        root_path ++ "imgui/imgui_widgets.cpp",
        root_path ++ "imgui/imgui_demo.cpp",
        root_path ++ "imgui/backends/imgui_impl_wgpu.cpp",
    }, c_flags.items);

    //Link libc and libc++, libc++ for wgpu
    cimgui.linkLibC();
    cimgui.linkLibCpp();

    return cimgui;
}

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    var cimgui = try create_cimgui(b, target, optimize);

    b.installArtifact(cimgui);
}

fn root() []const u8 {
    return std.fs.path.dirname(@src().file) orelse ".";
}

const root_path = root() ++ "/";
