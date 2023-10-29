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

        /**
         * @brief Set the size of this window.
         * 
         * @param w 
         * @param h 
         */
        virtual void SetSize(i32 w, i32 h) = 0;

        /**
         * @brief Get the width or height of this window.
         * 
         * @return u32 
         */
        virtual u32 GetWidth() = 0;
        virtual u32 GetHeight() = 0;

        /**
         * @brief Returns whether this window should close.
         * 
         * @return true 
         * @return false 
         */
        virtual bool ShouldClose() = 0;

        /**
         * @brief Get or set the window mode.
         * Options are:
         * WindowMode::NORMAL       (windowed)
         * WindowMode::FULLSCREEN
         * WindowMode::BORDERLESS
         * 
         * @param mode 
         */
        virtual void SetMode(WindowMode mode) = 0;
        virtual WindowMode GetMode() = 0;

        /**
         * @brief Returns a pointer to the internal window handle.
         * Should be cast by the user.
         * 
         * @return void* 
         */
        virtual void* GetNativeHandle() = 0;

        /**
         * @brief Create a window
         * 
         * @param desc 
         * @return Scope<Window> 
         */
        static Scope<Window> Create(const WindowDesc& desc);
    };
} // namespace octo


#endif