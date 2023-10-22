project "glad"
    -- Language
    language "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files
    {
        "./glad/**.h",
        "./glad/src/**.c"
    }

    includedirs
    {
        "./glad/include",
        "./glad/include/KHR",
        "./glad/include/glad/"
    }

    -- Linker
    links
    {

    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "GL" }
        defines { }

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }
        defines { }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"