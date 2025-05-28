#include "VectorN.h"

template <typename T, std::size_t N>
constexpr VectorN<T, N>::VectorN()
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] = T(0);
    }
}

template <typename T, std::size_t N>
constexpr VectorN<T, N>::VectorN(const T* elements_)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] = elements_[i];
    }
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::zero()
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = T(0);
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::ones()
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = T(1);
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::add(const VectorN<T, N>& v1, const VectorN<T, N>& v2)
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = v1.elements[i] + v2.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::sub(const VectorN<T, N>& v1, const VectorN<T, N>& v2)
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = v1.elements[i] - v2.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::mul(const VectorN<T, N>& v, T s)
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = v.elements[i] * s;
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::mul(T s, const VectorN<T, N>& v)
{
    return mul(v, s);
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::div(const VectorN<T, N>& v, T s)
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = v.elements[i] / s;
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr T VectorN<T, N>::dot(const VectorN<T, N>& v1, const VectorN<T, N>& v2)
{
    T result = T(0);
    for (std::size_t i = 0; i < N; ++i)
    {
        result += v1.elements[i] * v2.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
inline constexpr VectorN<T, N> VectorN<T, N>::normalize(const VectorN<T, N>& v)
{
    T mag = magnitude(v);
    return div(v, mag);
}

template <typename T, std::size_t N>
inline constexpr T VectorN<T, N>::magnitude(const VectorN<T, N>& v)
{
    return std::sqrt(dot(v, v));
}

template <typename T, std::size_t N>
inline constexpr T VectorN<T, N>::length(const VectorN<T, N>& v)
{
    return std::sqrt(dot(v, v));
}

template <typename T, std::size_t N>
inline constexpr T VectorN<T, N>::norm(const VectorN<T, N>& v)
{
    return std::sqrt(dot(v, v));
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator+() const
{
    return *this;
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator-() const
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = -elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator++()
{
    for (std::size_t i = 0; i < N; ++i)
    {
        ++elements[i];
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N> VectorN<T, N>::operator++(int)
{
    VectorN<T, N> temp = *this;
    ++(*this);
    return temp;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator--()
{
    for (std::size_t i = 0; i < N; ++i)
    {
        --elements[i];
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N> VectorN<T, N>::operator--(int)
{
    VectorN<T, N> temp = *this;
    --(*this);
    return temp;
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator+(const VectorN<T, N>& other) const
{
    return add(*this, other);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator-(const VectorN<T, N>& other) const
{
    return sub(*this, other);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> VectorN<T, N>::operator%(T scalar) const
{
    VectorN<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
    {
        result.elements[i] = elements[i] % scalar;
    }
    return result;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator+=(const VectorN<T, N>& other)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] += other.elements[i];
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator-=(const VectorN<T, N>& other)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] -= other.elements[i];
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator*=(T scalar)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] *= scalar;
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator/=(T scalar)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] /= scalar;
    }
    return *this;
}

template <typename T, std::size_t N>
VectorN<T, N>& VectorN<T, N>::operator%=(T scalar)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        elements[i] %= scalar;
    }
    return *this;
}

template <typename T, std::size_t N>
constexpr bool VectorN<T, N>::operator==(const VectorN<T, N>& other) const
{
    for (std::size_t i = 0; i < N; ++i)
    {
        if (elements[i] != other.elements[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T, std::size_t N>
constexpr bool VectorN<T, N>::operator!=(const VectorN<T, N>& other) const
{
    return !(*this == other);
}
