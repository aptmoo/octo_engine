project "OctoEngine"
    -- Language
    language "C++"
    cppdialect "C++17"

    -- Output
    kind "ConsoleApp"
    targetdir   "%{wks.location}/bin/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files
    {
        "src/**.h",
        "src/**.cpp",

        "platform/generic/**.h",
        "platform/generic/**.cpp",

        -- TODO: Build settings
        "platform/sg/**.h",
        "platform/sg/**.cpp"
    }

    includedirs
    {
        "src/",
        "platform/",
        "./",
        
        "%{wks.location}/Dependencies/",
        "%{wks.location}/Dependencies/glfw/include",
        "%{wks.location}/Dependencies/sokol/",
    }

    -- Linker
    links
    {
        "GLFW",
        "sokol"
    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "GL" }
        files { "platform/linux/**.h", "platform/linux/**.cpp" }
        targetname "OctoEngine.out"

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"