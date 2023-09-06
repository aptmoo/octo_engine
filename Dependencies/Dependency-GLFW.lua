project "GLFW"
    -- Language
    language "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files
    {
        "./glfw/**.h",
        "./glfw/src/**.c"
    }

    includedirs
    {
        "./glfw/include"
    }

    -- Linker
    links
    {

    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "X11", "Xi", "XCursor", "pthread" }
        defines { "_GLFW_X11" }

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }
        defines { "_GLFW_WIN32" }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"