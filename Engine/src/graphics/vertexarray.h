#ifndef GRAPHICS_VERTEXARRAY_H
#define GRAPHICS_VERTEXARRAY_H
#include "common/types.h"
#include "graphics/buffer.h"

namespace octo
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;  

        virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) = 0;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) = 0;

        static Ref<VertexArray> Create();
        static Ref<VertexArray> Create(const Ref<IndexBuffer>& indexBuffer, const Ref<VertexBuffer>& vertexBuffer);
    };
} // namespace octo


#endif