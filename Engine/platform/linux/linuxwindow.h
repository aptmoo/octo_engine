#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H
#include "common/window.h"
#include "GLFW/glfw3.h"

namespace octo
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowDesc& desc);
        virtual ~LinuxWindow();

                virtual void SetSize(u32 w, u32 h) override;
        virtual u32 GetWidth() override;
        virtual u32 GetHeight() override;

        virtual void SetMode(WindowMode mode) override;
        virtual WindowMode GetMode() override;

        virtual void* GetNativeHandle() override;
    private:
        GLFWwindow* m_Window;
        GLFWmonitor* m_Monitor;
    };
} // namespace octo


#endif