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
        "src/**.cpp"
    }

    includedirs
    {
        "src",

    }

    -- Linker
    links
    {
        "OctoShared",
    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl" }

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"