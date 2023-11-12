#include "bufferlayout.h"

namespace octo
{
    usize BufferElementTypeSize(const BufferElementType type)
    {
        switch (type)
        {
        case BufferElementType::FLOAT:  return 4;   // TODO: Should sizeof(float) be used? 
        case BufferElementType::FLOAT2: return 4 * 2;
        case BufferElementType::FLOAT3: return 4 * 3;
        case BufferElementType::FLOAT4: return 4 * 4;
        case BufferElementType::CHAR:   return 1;
        case BufferElementType::UCHAR:  return 1;
        case BufferElementType::BYTE:   return 1;
        case BufferElementType::UBYTE:  return 1;
        case BufferElementType::INT:    return 4;
        case BufferElementType::INT2:   return 4 * 2;
        case BufferElementType::INT3:   return 4 * 3;
        case BufferElementType::INT4:   return 4 * 4;
        case BufferElementType::UINT:   return 4;
        case BufferElementType::MAT4:   return 4 * 4 * 4;
        case BufferElementType::BOOL:   return 4;   // Bools have the same size as an uint.
                                                    // TODO: GLSL supports bool vec types(bvecN). We should probably support that.
                                                    // TODO: Double precision types might also be nice.
        case BufferElementType::NONE:   return 0;
        default: return 0;  // Catastrophic failure! 
        }
    }

    usize BufferElementComponentCount(const BufferElementType type)
    {
        switch (type)
        {
        case BufferElementType::FLOAT:  return 1;
        case BufferElementType::FLOAT2: return 1 * 2;
        case BufferElementType::FLOAT3: return 1 * 3;
        case BufferElementType::FLOAT4: return 1 * 4;
        case BufferElementType::INT:    return 1;
        case BufferElementType::INT2:   return 1 * 2;
        case BufferElementType::INT3:   return 1 * 3;
        case BufferElementType::INT4:   return 1 * 4;
        case BufferElementType::MAT4:   return 1 * 4 * 4;
        case BufferElementType::BOOL:   return 1;
        case BufferElementType::NONE:   return 1;
        default: return 0;  // Catastrophic failure! 
        }
    }

    void VertexBufferLayout::AddElement(BufferElementType type, bool normalized)
    {
        m_Elements.push_back({type, BufferElementTypeSize(type), normalized});
        m_Stride = 0;   // Hack to force recalculating strides when adding elements on the fly
    }

    u32 VertexBufferLayout::GetStride()
    {
        if(m_Stride != 0)
            return m_Stride;
        
        u32 offset = 0;
        for(auto& element : m_Elements)
        {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
        }

        return m_Stride;
    }
} // namespace octo
