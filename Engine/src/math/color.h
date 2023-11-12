#ifndef MATH_COLOR_H
#define MATH_COLOR_H
#include "common/types.h"

namespace octo
{
    struct Color
    {
        /**
         * @brief Simple direct color constructor. Boring!
         * 
         * @param red 
         * @param green 
         * @param blue 
         * @param alpha 
         */
        Color(u8 red, u8 green, u8 blue, u8 alpha = UINT8_MAX) : r(red), g(green), b(blue), a(alpha)
            {};

        inline static Color Red() { return {255, 0, 0}; }
        inline static Color Green() { return {0, 255, 0}; }
        inline static Color Blue() { return {0, 0, 255}; }

        u8 r, g, b, a;
    };
} // namespace octo


#endif