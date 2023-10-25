#include "glarray.h"
#include "glad/gl.h"

#include "glbuffer.h"
#include <iostream>

namespace octo
{
    unsigned BufferToGLType(const BufferElementType& type)
    {
        switch (type)
        {
        case BufferElementType::FLOAT:  return GL_FLOAT;
        case BufferElementType::FLOAT2: return GL_FLOAT;
        case BufferElementType::FLOAT3: return GL_FLOAT;
        case BufferElementType::FLOAT4: return GL_FLOAT;
        case BufferElementType::CHAR:   return GL_BYTE;
        case BufferElementType::UCHAR:  return GL_UNSIGNED_BYTE;
        case BufferElementType::BYTE:   return GL_BYTE;
        case BufferElementType::UBYTE:  return GL_UNSIGNED_BYTE;
        case BufferElementType::INT:    return GL_INT;
        case BufferElementType::INT2:   return GL_INT;
        case BufferElementType::INT3:   return GL_INT;
        case BufferElementType::INT4:   return GL_INT;
        case BufferElementType::UINT:   return GL_UNSIGNED_INT;
        case BufferElementType::MAT4:   return GL_FLOAT;
        case BufferElementType::BOOL:   return GL_BOOL;
        case BufferElementType::NONE:   return GL_INVALID_ENUM;
        default: return GL_INVALID_ENUM;  // Catastrophic failure! 
        }
    }


    GLVertexArray::GLVertexArray()
    {
        glCreateVertexArrays(1, &m_glID);
    }

    GLVertexArray::GLVertexArray(const Ref<IndexBuffer>& indexBuffer, const Ref<VertexBuffer>& vertexBuffer)
    {
        glCreateVertexArrays(1, &m_glID);
        this->SetIndexBuffer(indexBuffer);
        this->AddVertexBuffer(vertexBuffer);
    }

    GLVertexArray::~GLVertexArray()
    {
        glDeleteVertexArrays(1, &m_glID);
    }

    void GLVertexArray::Bind()
    {
        glBindVertexArray(m_glID);
    }

    void GLVertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void GLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer)
    {
        Ref<GLVertexBuffer> vertexBuffer = std::static_pointer_cast<GLVertexBuffer>(buffer);
        BufferLayout layout = vertexBuffer->GetLayout();
        glVertexArrayVertexBuffer(m_glID, m_BufferCount, vertexBuffer->GetID(), 0, layout.GetStride());
        u32 elementIndex = 0;
        
        for(const auto& element : layout)
        {
            glEnableVertexArrayAttrib(m_glID, elementIndex);
            glVertexArrayAttribFormat(m_glID, elementIndex, BufferElementComponentCount(element.Type), BufferToGLType(element.Type), element.Normalized, element.Offset);
            glVertexArrayAttribBinding(m_glID, elementIndex, m_BufferCount);
            elementIndex++;
        }

        m_BufferCount++;
        m_Buffers.push_back(buffer);
    }

    void GLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer)
    {
        glVertexArrayElementBuffer(m_glID, std::static_pointer_cast<GLIndexBuffer>(buffer)->GetID());
        m_IndexBuffer = buffer;
    }
} // namespace octo
