#ifndef GRAPHICS_DEVICE_H
#define GRAPHICS_DEVICE_H
#include "common/types.h"
#include "common/exception.h"

namespace octo
{
    DECLARE_EXCEPTION(GraphicsDeviceException);

    enum class GraphicsDebugSeverity
    {
        NOTIFICATION = 0,
        LOW,
        MEDIUM,
        HIGH,
    };

    class GraphicsDevice
    {
    public:
        virtual ~GraphicsDevice() = default;

        /**
         * @brief Clear the screen. Uses last set clear color.
         * 
         */
        virtual void Clear() = 0;

        /**
         * @brief 
         * 
         * @param r 
         * @param g 
         * @param b 
         */
        virtual void Clear(float r, float g, float b) = 0;

        /**
         * @brief Present the back buffer.
         * 
         */
        virtual void Present() = 0;

        /**
         * @brief Set the minimal debug message severity.
         * Applies only when debug is enabled.
         * 
         * @param severity 
         */
        virtual void SetMinDebugSeverity(GraphicsDebugSeverity severity) = 0;

        static Scope<GraphicsDevice> Create(void* handle);
    };

} // namespace octo


#endif