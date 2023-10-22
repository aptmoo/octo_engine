#ifndef COMMON_WINDOW_H
#define COMMON_WINDOW_H
#include "types.h"
#include <string>

namespace octo
{
    struct WindowDesc
    {
        std::string Title;
        i32 Width, Height;
    };

    enum class WindowMode
    {
        NORMAL = 0,
        FULLSCREEN,
        BORDERLESS,
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void Update() = 0;

        virtual void SetSize(i32 w, i32 h) = 0;
        virtual u32 GetWidth() = 0;
        virtual u32 GetHeight() = 0;

        virtual bool ShouldClose() = 0;

        virtual void SetMode(WindowMode mode) = 0;
        virtual WindowMode GetMode() = 0;

        virtual void* GetNativeHandle() = 0;

        static Scope<Window> Create(const WindowDesc& desc);
    };
} // namespace octo


#endif