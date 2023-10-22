#ifndef RENDERER_CONTEXT_H
#define RENDERER_CONTEXT_H
#include "common/types.h"

namespace octo
{
    class GrapicsContext
    {
    public:
        virtual ~GrapicsContext() = default;
        
        virtual void Present() = 0;

        static Scope<GrapicsContext> Create(void* windowHandle);
    };
} // namespace octo


#endif