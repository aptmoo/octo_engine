project "OctoShared"
    -- Language
    language "C++"
    cppdialect "C++17"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files
    {
        "./**.h",
        "./**.cpp"
    }

    includedirs
    {
        "./"
    }

    -- Linker
    links
    {

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