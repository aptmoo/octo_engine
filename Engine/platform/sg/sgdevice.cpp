#include "sgdevice.h"
#include "sokol_gfx.h"

#include "GLFW/glfw3.h"

namespace octo
{
    static struct
    {
        sg_buffer quadBuffer;
    } device_state;
    

    void DrawFullscreenImage()
    {

    }
    
    SGDevice::SGDevice(void* handle)
        : m_WindowHandle(handle)
    {
        sg_desc apiDesc = {};
        sg_setup(apiDesc);

        glfwMakeContextCurrent((GLFWwindow*)handle);
    }

    SGDevice::~SGDevice()
    {
        sg_shutdown();
    }

    void SGDevice::Flush()
    {
        sg_commit();
    }

    void SGDevice::Present()
    {
        glfwSwapBuffers((GLFWwindow*)m_WindowHandle);
    }
} // namespace octo
