#include "gldevice.h"

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace octo
{
    static void GLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* msg, const void*)
    {
        auto const src_str = [source]() {
            switch (source)
            {
            case GL_DEBUG_SOURCE_API: return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "Window system";
            case GL_DEBUG_SOURCE_SHADER_COMPILER: return "Shader compiler";
            case GL_DEBUG_SOURCE_THIRD_PARTY: return "Thirdparty/vendor";
            case GL_DEBUG_SOURCE_APPLICATION: return "Application";
            case GL_DEBUG_SOURCE_OTHER: return "Misc";
            default: return "Unknown";
            }
	    }();

        auto const type_str = [type]() {
            switch (type)
            {
            case GL_DEBUG_TYPE_ERROR: return "ERROR";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
            case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
            case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
            case GL_DEBUG_TYPE_MARKER: return "MARKER";
            case GL_DEBUG_TYPE_OTHER: return "OTHER";
            default: "Unknown";
            }
        }();

        auto const severity_str = [severity]() {
            switch (severity) {
            case GL_DEBUG_SEVERITY_NOTIFICATION: return "Notification";
            case GL_DEBUG_SEVERITY_LOW: return "Low";
            case GL_DEBUG_SEVERITY_MEDIUM: return "Medium";
            case GL_DEBUG_SEVERITY_HIGH: return "High";
            default: "Unknown";
            }
        }();

        std::cout << "OpenGL error from '" << src_str << "' of type '" << type_str << "' and severity '" << severity_str << "':\n";
        std::cout << msg << '\n'; 
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
        glDebugMessageCallback(GLMessageCallback, nullptr);
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

    void GLGraphicsDevice::SetMinDebugSeverity(GraphicsDebugSeverity severity)
    {
        // TODO: implement
        auto const severity_str = [severity]() {
            switch (severity) {
            case GraphicsDebugSeverity::NOTIFICATION : return GL_DEBUG_SEVERITY_NOTIFICATION;
            case GraphicsDebugSeverity::LOW : return GL_DEBUG_SEVERITY_LOW;
            case GraphicsDebugSeverity::MEDIUM: return GL_DEBUG_SEVERITY_MEDIUM;
            case GraphicsDebugSeverity::HIGH: return GL_DEBUG_SEVERITY_HIGH;
            default: return GL_DEBUG_SEVERITY_NOTIFICATION;
		}
        }();
    }   

} // namespace octo
