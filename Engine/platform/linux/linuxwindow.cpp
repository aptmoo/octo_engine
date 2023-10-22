#include "linuxwindow.h"

namespace octo
{
    /**
     * @brief The amount of windows created, used to init and deinit glfw.
     * Only 8 bits, since your not really meant to create more than 2 windows, let alone more than 255
     *
     */
    static u8 s_WindowCount = 0;

    LinuxWindow::LinuxWindow(const WindowDesc &desc)
    {
        if (s_WindowCount == 0)
        {
            // TODO: Error handling
            int success = glfwInit();
        }

        const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, vidmode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, vidmode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, vidmode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, vidmode->refreshRate);
        glfwWindowHint(GLFW_RESIZABLE, false);

        m_Window = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), nullptr, nullptr);
        s_WindowCount++;

        m_WindowData.Height = desc.Height;
        m_WindowData.Width = desc.Width;
        m_WindowData.Title = desc.Title;
    }

    LinuxWindow::~LinuxWindow()
    {
        glfwDestroyWindow(m_Window);
        s_WindowCount--;

        if(s_WindowCount == 0)
        {
            glfwTerminate();
        }
    }

    void LinuxWindow::Update()
    {
        glfwGetWindowSize(m_Window, &m_WindowData.Width, &m_WindowData.Height);

        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

    void LinuxWindow::SetSize(i32 w, i32 h)
    {
        glfwSetWindowSize(m_Window, w, h);
    }

    u32 LinuxWindow::GetWidth()
    {
        return m_WindowData.Width;
    }

    u32 LinuxWindow::GetHeight()
    {
        return m_WindowData.Height;
    }

    bool LinuxWindow::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void LinuxWindow::SetMode(WindowMode mode)
    {
        switch (mode)
        {
        case WindowMode::NORMAL:
            glfwSetWindowMonitor(m_Window, nullptr, 0, 0, m_WindowData.Width, m_WindowData.Height, glfwGetVideoMode(m_Monitor)->refreshRate);
            break;
        case WindowMode::FULLSCREEN:
            glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, m_WindowData.Width, m_WindowData.Height, glfwGetVideoMode(m_Monitor)->refreshRate);
        default:
            break;
        }

        m_WindowData.Mode = mode;
    }

    WindowMode LinuxWindow::GetMode()
    {
        return m_WindowData.Mode;
    }

    void* LinuxWindow::GetNativeHandle()
    {
        return (void*)m_Window;
    }


} // namespace octo
