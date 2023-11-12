#ifndef GRAPHICS_BUFFERLAYOUT_H
#define GRAPHICS_BUFFERLAYOUT_H
#include "common/types.h"
#include <vector>
#include <string>

namespace octo
{
    /**
     * @brief Platform independent element type enum.
     * TODO: Should there be a more generic type used everywhere?
     * 
     */
    enum class BufferElementType
    {
        NONE = 0, FLOAT, FLOAT2, FLOAT3, FLOAT4, 
        CHAR, UCHAR, BYTE, UBYTE, 
        INT, INT2, INT3, INT4, UINT, 
        MAT4, 
        BOOL,
    };

    /**
     * @brief The size of this type on the GPU.
     * 
     * @param type 
     * @return usize 
     */
    usize BufferElementTypeSize(const BufferElementType type);

    /**
     * @brief Get the amount of components of a certain type.
     * 
     * @param type 
     * @return usize 
     */
    usize BufferElementComponentCount(const BufferElementType type);

    struct VertexBufferElement
    {
        BufferElementType Type;
        u32 Offset;
        u32 Size;
        bool Normalized;

        VertexBufferElement(BufferElementType type, u32 size, bool normalized = false)
            : Type(type), Size(size), Normalized(normalized)
        {}
    };

    struct VertexBufferLayout
    {
    public:
        /**
         * @brief Add an element to this layout.
         * 
         * @param type 
         * @param normalized 
         */
        void AddElement(BufferElementType type, bool normalized = false);

        /**
         * @brief Get the internal elements vector.
         * 
         * @return const std::vector<VertexBufferElement> 
         */
        inline const std::vector<VertexBufferElement> GetElements() { return m_Elements; }

        /**
         * @brief Get or calculate the stride of this layout.
         * 
         * @return u32 
         */
        u32 GetStride();

        /**
         * @brief Iterators. Needed for for loops.
         * 
         * @return std::vector<VertexBufferElement>::iterator 
         */
        std::vector<VertexBufferElement>::iterator begin() { return m_Elements.begin(); }
        std::vector<VertexBufferElement>::iterator end() { return m_Elements.end(); }
        std::vector<VertexBufferElement>::const_iterator begin() const { return m_Elements.begin(); }
        std::vector<VertexBufferElement>::const_iterator end() const { return m_Elements.end(); }

    private:
        u32 m_Stride = 0;
        std::vector<VertexBufferElement> m_Elements;
    };

    struct UniformBufferElement
    {
        std::string Name;
        BufferElementType Type;
        u32 Offset;
        u32 Size;
        bool Normalized;
    };

    class UniformBufferLayout
    {
    public:
        

    private:
        u32 m_Stride = 0;
        std::vector<UniformBufferElement> m_Elements;
    };

} // namespace octo


#endif