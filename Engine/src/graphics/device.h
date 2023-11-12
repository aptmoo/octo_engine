#ifndef GRAPHICS_DEVICE_H
#define GRAPHICS_DEVICE_H
#include "common/types.h"
#include "math/color.h"
#include "common/exception.h"

namespace octo
{
    DECLARE_EXCEPTION(GraphicsDeviceException);

    class GraphicsDevice
    {
    public:
        virtual ~GraphicsDevice() = default;

        /**
         * @brief 
         * 
         */
        virtual void Flush() = 0;

        /**
         * @brief Present the back buffer.
         * 
         */
        virtual void Present() = 0;

        virtual void Clear(Color color) = 0;

        /**
         * @brief Create a device using a window handle.
         * 
         * @param handle 
         * @return Scope<GraphicsDevice> 
         */
        static Scope<GraphicsDevice> Create(void* handle);
    };

} // namespace octo


#endif