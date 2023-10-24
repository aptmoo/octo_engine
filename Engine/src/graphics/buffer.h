#ifndef GRAPHICS_BUFFER_H
#define GRAPHICS_BUFFER_H
#include "common/types.h"
#include "graphics/bufferlayout.h"

#include <vector>

namespace octo
{
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        /**
         * @brief Get the internal layout. This layout must be private in a implementation subclass.
         * This is done to avoid making "brittle bases".
         * 
         * @return const BufferLayout& 
         */
        virtual const BufferLayout& GetLayout() = 0;

        /**
         * @brief Set the layout of this buffer.
         * 
         * @param layout 
         */
        virtual void SetLayout(const BufferLayout& layout) = 0;

        /**
         * @brief Create a vertex buffer using raw data.
         * 
         * @param data 
         * @param dataSize 
         * @return Ref<VertexBuffer> 
         */
        static Ref<VertexBuffer> Create(void* data, usize dataSize);

        /**
         * @brief Create a vertex buffer using a layout.
         * 
         * @param data 
         * @param elements 
         * @param layout 
         * @return Ref<VertexBuffer> 
         */
        static Ref<VertexBuffer> Create(void* data, u32 elements, BufferLayout& layout);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void SetData(const void* data, u32 elements, BufferElementType type) = 0;

        /**
         * @brief Returns the amount of elements stored in this buffer.
         * 
         * @return u32 
         */
        virtual u32 GetElementCount() = 0;

        /**
         * @brief Create a index buffer using raw data.
         * 
         * @param data 
         * @param elements 
         * @param type 
         * @return Ref<IndexBuffer> 
         */
        static Ref<IndexBuffer> Create(const void* data, u32 elements, BufferElementType type);
    };
} // namespace octo


#endif