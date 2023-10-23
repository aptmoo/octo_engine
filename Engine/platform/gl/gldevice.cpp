#include "gldevice.h"

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace octo
{
    GLGraphicsDevice::GLGraphicsDevice(void* handle)
        : m_WindowHandle(handle)
    {
        glfwMakeContextCurrent((GLFWwindow*)handle);

        // TODO: Error handling
        int status = gladLoadGL(glfwGetProcAddress);
        if(!status)
        {
            throw GraphicsDeviceException("Failed to init GLAD!");
        }

        std::cout << glGetString(GL_VERSION) << '\n';
    }

    GLGraphicsDevice::~GLGraphicsDevice()
    {}

    void GLGraphicsDevice::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    }

    void GLGraphicsDevice::Clear(float r, float g, float b)
    {
        glClearColor(r, g, b, 0.0f);
        this->Clear();
    }

    void GLGraphicsDevice::Present()
    {
        glfwSwapBuffers((GLFWwindow*)m_WindowHandle);
    }

} // namespace octo
