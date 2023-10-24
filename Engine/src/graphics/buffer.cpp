#include "buffer.h"
#include "gl/glbuffer.h"

namespace octo
{
    Ref<VertexBuffer> VertexBuffer::Create(void* data, usize dataSize)
    {
        return MakeRef<GLVertexBuffer>(data, dataSize);
    }

    Ref<VertexBuffer> VertexBuffer::Create(void* data, u32 elements, BufferLayout& layout)
    {
        return MakeRef<GLVertexBuffer>(data, elements, layout);
    }

    Ref<IndexBuffer> IndexBuffer::Create(const void* data, u32 elements, BufferElementType type)
    {
        return MakeRef<GLIndexBuffer>(data, elements, type);
    }
} // namespace octo