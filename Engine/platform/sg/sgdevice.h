#ifndef SG_DEVICE_H
#define SG_DEVICE_H
#include "graphics/device.h"

namespace octo
{
    class SGDevice : public GraphicsDevice
    {
    public:
        SGDevice(void* handle);
        virtual ~SGDevice();

        virtual void Flush() override;
        virtual void Present() override;
    private:
        void* m_WindowHandle;
    };
} // namespace octo


#endif