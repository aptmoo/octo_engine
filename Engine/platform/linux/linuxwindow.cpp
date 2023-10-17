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
            glfwInit();
        }

        const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, vidmode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, vidmode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, vidmode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, vidmode->refreshRate);
        glfwWindowHint(GLFW_RESIZABLE, false);

        m_Window = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), nullptr, nullptr);
        s_WindowCount++;
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

} // namespace octo
