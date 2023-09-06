workspace "Octo"
    configurations { "Debug", "Release" }
    startproject "OctoEngine"

    architecture "x64"

include "Engine/Build-Octo.lua"
include "Shared/Build-Shared.lua"

include "Dependencies/Dependency-GLFW.lua"