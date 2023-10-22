workspace "Octo"
    configurations { "Debug", "Release" }
    startproject "OctoEngine"

    architecture "x64"

include "Engine/Build-Octo.lua"

include "Dependencies/Dependency-GLFW.lua"
include "Dependencies/Dependency-GLAD.lua"