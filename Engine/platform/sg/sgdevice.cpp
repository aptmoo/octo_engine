#include "sgdevice.h"
#include "sokol_gfx.h"

#include "GLFW/glfw3.h"

namespace octo
{
    SGDevice::SGDevice(void* handle)
        : m_WindowHandle(handle)
    {
        sg_desc apiDesc = {};
        sg_setup(apiDesc);
    }

    SGDevice::~SGDevice()
    {
        sg_shutdown();
    }

    void SGDevice::Present()
    {
        glfwSwapBuffers((GLFWwindow*)m_WindowHandle);
    }
} // namespace octo
