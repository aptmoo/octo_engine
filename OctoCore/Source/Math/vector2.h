#ifndef MATH_VEC2_H
#define MATH_VEC2_H
#include "Core/types.h"

namespace octo
{
    template<typename T>
    struct __Vector2Base
    {
        union
        {
            T x, y;
            T v[2];
        };

        /* Constructors */
        __Vector2Base<T>()
        {
            this->x = 0;
            this->y = 0;
        }

        __Vector2Base<T>(T x, T y)
        {
            this->x = x;
            this->y = y;
        }

        __Vector2Base(T c)
        {
            this->x = c;
            this->y = c;
        }

        __Vector2Base(T arr[2])
        {
            this->x = arr[0];
            this->y = arr[1];
        }

        /* Functions */
        static __Vector2Base<T> Add(const __Vector2Base<T>& a, const __Vector2Base<T>& b)
        {
            __Vector2Base<T> v;
            v.x = a.x + b.x;
            v.y = a.y + b.y;
            return v;
        }

        static __Vector2Base<T> Add(const __Vector2Base<T>& a, T c)
        {
            __Vector2Base<T> v;
            v.x = a.x + c;
            v.y = a.y + c;
            return v;
        }

        static __Vector2Base<T> Subtract(const __Vector2Base<T>& a, const __Vector2Base<T>& b)
        {
            __Vector2Base<T> v;
            v.x = a.x - b.x;
            v.y = a.y - b.y;
            return v;
        }

        static __Vector2Base<T> Subtract(const __Vector2Base<T>& a, T c)
        {
            __Vector2Base<T> v;
            v.x = a.x - c;
            v.y = a.y - c;
            return v;
        }

        static __Vector2Base<T> Multiply(const __Vector2Base<T>& a, const __Vector2Base<T>& b)
        {
            __Vector2Base<T> v;
            v.x = a.x * b.x;
            v.y = a.y * b.y;
            return v;
        }

        static __Vector2Base<T> Multiply(const __Vector2Base<T>& a, T c)
        {
            __Vector2Base<T> v;
            v.x = a.x * c;
            v.y = a.y * c;
            return v;
        }

        static __Vector2Base<T> Divide(const __Vector2Base<T>& a, const __Vector2Base<T>& b)
        {
            __Vector2Base<T> v;
            v.x = a.x / b.x;
            v.y = a.y / b.y;
            return v;
        }

        static __Vector2Base<T> Divide(const __Vector2Base<T>& a, T c)
        {
            __Vector2Base<T> v;
            v.x = a.x / c;
            v.y = a.y / c;
            return v;
        }

        /* Operators */
        T operator[](const usize n)
        {
            if(n > 2)
                return 0;
            return v[n];
        }

        __Vector2Base<T> operator+(__Vector2Base<T> other)
        {
            return Add(*this, other);
        }

        __Vector2Base<T> operator+(T c)
        {
            return Add(*this, c);
        }

        __Vector2Base<T> operator-(__Vector2Base<T> other)
        {
            return Subtract(*this, other);
        }

        __Vector2Base<T> operator-(T c)
        {
            return Subtract(*this, c);
        }

        __Vector2Base<T> operator*(__Vector2Base<T> other)
        {
            return Multiply(*this, other);
        }

        __Vector2Base<T> operator*(T c)
        {
            return Multiply(*this, c);
        }

        __Vector2Base<T> operator/(__Vector2Base<T> other)
        {
            return Divide(*this, other);
        }

        __Vector2Base<T> operator/(T c)
        {
            return Divide(*this, c);
        }

        /* Constants */
        inline static __Vector2Base<T> One() { return {1, 1}; }
        inline static __Vector2Base<T> Zero() { return {0, 0}; }

        inline static __Vector2Base<T> Up() { return {0, 1}; }
        inline static __Vector2Base<T> Forward() { return {1, 0}; }
    };

    using Vector2 = __Vector2Base<float>;
    
} // namespace octo


#endif