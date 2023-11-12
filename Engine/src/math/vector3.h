#ifndef MATH_VEC3_H
#define MATH_VEC3_H
#include "common/types.h"

namespace octo
{
    template<typename T>
    struct __Vector3Base
    {
        union
        {
            T x, y, z;
            T v[3];
        };

        /* Constructors */
        __Vector3Base<T>()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        __Vector3Base<T>(T x, T y, T z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        __Vector3Base<T>(T x, T y)
        {
            this->x = x;
            this->y = y;
            this->z = 0;
        }

        __Vector3Base(T c)
        {
            this->x = c;
            this->y = c;
            this->z = c;
        }

        __Vector3Base(T arr[3])
        {
            this->x = arr[0];
            this->y = arr[1];
            this->z = arr[2];
        }

        /* Functions */
        static __Vector3Base<T> Add(const __Vector3Base<T>& a, const __Vector3Base<T>& b)
        {
            __Vector3Base<T> v;
            v.x = a.x + b.x;
            v.y = a.y + b.y;
            v.z = a.z + b.z;
            return v;
        }

        static __Vector3Base<T> Add(const __Vector3Base<T>& a, T c)
        {
            __Vector3Base<T> v;
            v.x = a.x + c;
            v.y = a.y + c;
            v.z = a.z + c;
            return v;
        }

        static __Vector3Base<T> Subtract(const __Vector3Base<T>& a, const __Vector3Base<T>& b)
        {
            __Vector3Base<T> v;
            v.x = a.x - b.x;
            v.y = a.y - b.y;
            v.z = a.z - b.z;
            return v;
        }

        static __Vector3Base<T> Subtract(const __Vector3Base<T>& a, T c)
        {
            __Vector3Base<T> v;
            v.x = a.x - c;
            v.y = a.y - c;
            v.z = a.z - c;
            return v;
        }

        static __Vector3Base<T> Multiply(const __Vector3Base<T>& a, const __Vector3Base<T>& b)
        {
            __Vector3Base<T> v;
            v.x = a.x * b.x;
            v.y = a.y * b.y;
            v.z = a.z * b.z;
            return v;
        }

        static __Vector3Base<T> Multiply(const __Vector3Base<T>& a, T c)
        {
            __Vector3Base<T> v;
            v.x = a.x * c;
            v.y = a.y * c;
            v.z = a.z * c;
            return v;
        }

        static __Vector3Base<T> Divide(const __Vector3Base<T>& a, const __Vector3Base<T>& b)
        {
            __Vector3Base<T> v;
            v.x = a.x / b.x;
            v.y = a.y / b.y;
            v.z = a.z / b.z;
            return v;
        }

        static __Vector3Base<T> Divide(const __Vector3Base<T>& a, T c)
        {
            __Vector3Base<T> v;
            v.x = a.x / c;
            v.y = a.y / c;
            v.z = a.z / c;
            return v;
        }

        /* Operators */
        T operator[](const usize n)
        {
            if(n > 3)
                return 0;
            return v[n];
        }

        __Vector3Base<T> operator+(__Vector3Base<T> other)
        {
            return Add(*this, other);
        }

        __Vector3Base<T> operator+(T c)
        {
            return Add(*this, c);
        }

        __Vector3Base<T> operator-(__Vector3Base<T> other)
        {
            return Subtract(*this, other);
        }

        __Vector3Base<T> operator-(T c)
        {
            return Subtract(*this, c);
        }

        __Vector3Base<T> operator*(__Vector3Base<T> other)
        {
            return Multiply(*this, other);
        }

        __Vector3Base<T> operator*(T c)
        {
            return Multiply(*this, c);
        }

        __Vector3Base<T> operator/(__Vector3Base<T> other)
        {
            return Divide(*this, other);
        }

        __Vector3Base<T> operator/(T c)
        {
            return Divide(*this, c);
        }

        /* Constants */
        inline static __Vector3Base<T> One() { return {1, 1, 1}; }
        inline static __Vector3Base<T> Zero() { return {0, 0, 0}; }

        inline static __Vector3Base<T> Right() { return {0, 0, 1}; }
        inline static __Vector3Base<T> Up() { return {0, 1, 0}; }
        inline static __Vector3Base<T> Forward() { return {1, 0, 0}; }
    };
    
} // namespace octo


#endif