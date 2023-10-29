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

        /**
         * @brief Present the back buffer.
         * 
         */
        virtual void Present() = 0;

        static Scope<GraphicsDevice> Create(void* handle);
    };

} // namespace octo


#endif