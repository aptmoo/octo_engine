#include "gldevice.h"

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace octo
{
    static void GLMessageCallback(GLenum src, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* msg, const void*)
    {
        
    }

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

        #ifndef NDEBUG
        glEnable(GL_DEBUG_OUTPUT);
        #endif
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
