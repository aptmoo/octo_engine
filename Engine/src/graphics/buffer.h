#ifndef GRAPHICS_BUFFER_H
#define GRAPHICS_BUFFER_H
#include "common/types.h"
#include "graphics/bufferlayout.h"

namespace octo
{
    class GPUBuffer
    {
    public:
        virtual ~GPUBuffer() = default;

        static Ref<GPUBuffer> Create(void* data);
    };
} // namespace octo


#endif