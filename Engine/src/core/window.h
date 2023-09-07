#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H
#include "common/types.h"
#include <string>

namespace octo
{

    struct WindowProps
    {
        u32 Width, Height;
        std::string Title;
    };

    /**
     * @brief Base window interface class.
     * 
     */
    class Window
    {
    public:
        /**
         * @brief Virtual destructor.
         * Should be overridden by implementation subclasses.
         * 
         */
        virtual ~Window() = default;

        /* Interface */
        /**
         * @brief Update this window.
         * 
         */
        virtual void Update() = 0;

        /**
         * @brief Get the size of this window.
         * 
         * @return int 
         */
        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;

        /**
         * @brief Get the native window handle, as a void pointer.
         * 
         * @return void* 
         */
        virtual void* GetNativeHandle() = 0;

        /* Creation funcs */
        static Scope<Window> Create(const WindowProps& props);
    };

} // namespace octo


#endif