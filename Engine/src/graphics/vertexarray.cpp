#include "vertexarray.h"
#include "gl/glarray.h"

namespace octo
{
    Ref<VertexArray> VertexArray::Create()
    {
        return MakeRef<GLVertexArray>();
    }

    Ref<VertexArray> VertexArray::Create(const Ref<IndexBuffer>& indexBuffer, const Ref<VertexBuffer>& vertexBuffer)
    {
        return MakeRef<GLVertexArray>(indexBuffer, vertexBuffer);
    }
} // namespace octo
