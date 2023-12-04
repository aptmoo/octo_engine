#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H
#include "Core/types.h"
#include "string"

namespace name
{ 
    struct WindowDesc
    {
        std::string Title;
        u32 Width, Height;
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        /**
         * @brief Returns a handle to the native window.
         * 
         * @return void* 
         */
        virtual void* GetNativeHandle() = 0;
    private:

    };
} // namespace name


#endif