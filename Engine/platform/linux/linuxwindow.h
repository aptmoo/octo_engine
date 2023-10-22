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

        virtual void Update() override;

        virtual void SetSize(i32 w, i32 h) override;
        virtual u32 GetWidth() override;
        virtual u32 GetHeight() override;

        virtual bool ShouldClose() override;

        virtual void SetMode(WindowMode mode) override;
        virtual WindowMode GetMode() override;

        virtual void* GetNativeHandle() override;
    private:
        GLFWwindow* m_Window;
        GLFWmonitor* m_Monitor;

        /*
            Private copy of the data to avoid fetching window information multiple times per frame.
        */
        struct
        {
            std::string Title;
            WindowMode Mode;
            i32 Width;
            i32 Height;
        } m_WindowData;
        
    };
} // namespace octo


#endif