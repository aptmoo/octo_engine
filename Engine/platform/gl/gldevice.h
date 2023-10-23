#ifndef GL_DEVICE_H
#define GL_DEVICE_H
#include "graphics/device.h"

namespace octo
{
    class GLGraphicsDevice : public GraphicsDevice
    {
    public:
        GLGraphicsDevice(void* handle);
        virtual ~GLGraphicsDevice();

        virtual void Clear() override;
        virtual void Clear(float r, float g, float b) override;

        virtual void Present() override;
    private:
        void* m_WindowHandle;
    };
} // namespace octo


#endif