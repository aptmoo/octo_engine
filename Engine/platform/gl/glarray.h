#ifndef GL_ARRAY_H
#define GL_ARRAY_H
#include "common/types.h"
#include "graphics/vertexarray.h"

namespace octo
{
    class GLVertexArray : public VertexArray
    {
    public:
        GLVertexArray();
        GLVertexArray(const Ref<IndexBuffer>& indexBuffer, const Ref<VertexBuffer>& vertexBuffer);
        virtual ~GLVertexArray();

        virtual void Bind() override;
        virtual void Unbind() override;  

        virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) override;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) override;
    private:
        u32 m_glID;

        u32 m_BufferCount = 0;
        std::vector<Ref<VertexBuffer>> m_Buffers;
        Ref<IndexBuffer> m_IndexBuffer;
    };
} // namespace octo


#endif