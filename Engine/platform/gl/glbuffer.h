#ifndef GL_BUFFER_H
#define GL_BUFFER_H
#include "common/types.h"
#include "graphics/buffer.h"

namespace octo
{
    class GLVertexBuffer : public VertexBuffer
    {
    public:
        GLVertexBuffer(void* data, usize dataSize);
        GLVertexBuffer(void* data, u32 elements, BufferLayout& layout);
        virtual ~GLVertexBuffer();

        virtual const BufferLayout& GetLayout() override { return m_Layout; };
        virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; };
    private:
        BufferLayout m_Layout;
        u32 m_glID;
    };

    class GLIndexBuffer : public IndexBuffer
    {
    public:
        GLIndexBuffer(const void* data, u32 elements, BufferElementType type);
        virtual ~GLIndexBuffer();

        virtual void SetData(const void* data, u32 elements, BufferElementType type) override;

        virtual u32 GetElementCount() override { return m_ElementCount; }
    private:
        u32 m_ElementCount;
        u32 m_glID;
    };
} // namespace octo


#endif