#include "sgdevice.h"
#include "sokol_gfx.h"

#include "GLFW/glfw3.h"

#include <iostream>

namespace octo
{
    void SGLogCallback(
        const char *tag,              
        uint32_t log_level,           
        uint32_t log_item_id,         
        const char *message_or_null,  
        uint32_t line_nr,             
        const char *filename_or_null, 
        void *user_data)
    {
        if(message_or_null)
        {
            std::cout << message_or_null << '\n';
        }
    }

        SGDevice::SGDevice(void *handle)
        : m_WindowHandle(handle)
    {
        sg_desc apiDesc = {};
        apiDesc.logger = sg_logger{SGLogCallback, nullptr};
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
