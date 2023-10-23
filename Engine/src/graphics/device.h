#ifndef GRAPHICS_DEVICE_H
#define GRAPHICS_DEVICE_H
#include "common/types.h"
#include "common/exception.h"

namespace octo
{
    DECLARE_EXCEPTION(GraphicsDeviceException);

    class GraphicsDevice
    {
    public:
        virtual ~GraphicsDevice() = default;

        virtual void Clear() = 0;
        virtual void Clear(float r, float g, float b) = 0;

        virtual void Present() = 0;

        static Scope<GraphicsDevice> Create(void* handle);
    };

} // namespace octo


#endif