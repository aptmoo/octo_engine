#include "glbuffer.h"

#include "glad/gl.h"

namespace octo
{
    GLVertexBuffer::GLVertexBuffer(void* data, usize dataSize)
    {
        glCreateBuffers(1, &m_glID);
        glNamedBufferStorage(m_glID, dataSize, data, GL_DYNAMIC_STORAGE_BIT);
    }

    GLVertexBuffer::GLVertexBuffer(void* data, u32 elements, BufferLayout& layout)
    {
        glCreateBuffers(1, &m_glID);
        glNamedBufferStorage(m_glID, layout.GetStride() * elements, data, GL_DYNAMIC_STORAGE_BIT);
    }

    GLVertexBuffer::~GLVertexBuffer()
    {
        glDeleteBuffers(1, &m_glID);
    }

    GLIndexBuffer::GLIndexBuffer(const void* data, u32 elements, BufferElementType type)
        : m_ElementCount(elements)
    {
        glCreateBuffers(1, &m_glID);
        glNamedBufferStorage(m_glID, elements * BufferElementTypeSize(type), data, GL_DYNAMIC_STORAGE_BIT);
    }

    GLIndexBuffer::~GLIndexBuffer()
    {
        glDeleteBuffers(1, &m_glID);
    }

    void GLIndexBuffer::SetData(const void* data, u32 elements, BufferElementType type)
    {
        glNamedBufferStorage(m_glID, elements * BufferElementTypeSize(type), data, GL_DYNAMIC_STORAGE_BIT);
        m_ElementCount = elements;
    }
} // namespace octo
