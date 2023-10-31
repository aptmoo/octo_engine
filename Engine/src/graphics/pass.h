#ifndef GRAPHICS_PASS_H
#define GRAPHICS_PASS_H
#include "common/types.h"

namespace octo
{
    enum class StoreAction : u32
    {
        DEFAULT = 0,
        CLEAR,
        LOAD,
        DONTCARE,
    };

    enum class LoadAction : u32
    {
        DEFAULT = 0,
        STORE,
        DONTCARE,
    };

    class Pass
    {
    public:
        virtual ~Pass() = default;

        static Ref<Pass> Create();
    };
} // namespace octo


#endif