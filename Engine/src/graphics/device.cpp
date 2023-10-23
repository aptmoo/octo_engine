#include "device.h"
#include "gl/gldevice.h"

namespace octo
{
    Scope<GraphicsDevice> GraphicsDevice::Create(void* handle)
    {
        // TODO: platform switching
        return MakeScope<GLGraphicsDevice>(handle);
    }
} // namespace octo
