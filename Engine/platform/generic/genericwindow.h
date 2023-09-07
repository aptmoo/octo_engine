#ifndef GENERIC_WINDOW_H
#define GENERIC_WINDOW_H
#include "core/window.h"
#include "GLFW/glfw3.h"

namespace octo
{
    class GenericWindow : public Window
    {
    public:
        GenericWindow(const WindowProps& props);
        virtual ~GenericWindow();

        virtual void Update() = 0;
        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;
        virtual void* GetNativeHandle() override { return (void*)m_Window; };

    private:
        GLFWwindow* m_Window;
    };

} // namespace octo


#endif