#include "device.h"
#include "sg/sgdevice.h"

namespace octo
{
    Scope<GraphicsDevice> GraphicsDevice::Create(void* handle)
    {
        // TODO: platform switching
        return MakeScope<SGDevice>(handle);
        
    }
} // namespace octo
