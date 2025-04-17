#include "Vector3.h"

template <typename T>
Vector3<T>::Vector3()
{
}

template <typename T>
Vector3<T>::Vector3(T x_=0, T y_=0)
{
    x = x_;
    y = y_;
}

template <typename T>
Vector3<T> Vector3<T>::add(Vector3<T> v1, Vector3<T> v2)
{
    return {v1.x+v2.x, v1.y+v2.y};
}

template <typename T>
Vector3<T> Vector3<T>::sub(Vector3<T> v1, Vector3<T> v2)
{
    return {v1.x-v2.x, v1.y-v2.y};
}

template <typename T>
Vector3<T> Vector3<T>::mul(Vector3<T> v1, T s)
{
    return {s*v1.x, s*v1.y};
}

template <typename T>
Vector3<T> Vector3<T>::mul(T s, Vector3<T> v2)
{
    return {s*v1.x, s*v1.y};
}

template <typename T>
Vector3<T> Vector3<T>::div(Vector3<T> v1, T s)
{
    return {v1.x/s, v1.y/s};
}

template <typename T>
T Vector3<T>::normalize(Vector3<T> v1)
{
    T norm_v1 = sqrt(v1.x*v1.x + v1.y*v1.y);
    return {v1.x/norm_v1, v1.y/norm_v1};
}

template <typename T>
T Vector3<T>::norm(Vector3<T> v1)
{
    return sqrt(v1.x*v1.x + v1.y*v1.y);
}

template <typename T>
T Vector3<T>::len(Vector3<T> v1)
{
    return sqrt(v1.x*v1.x + v1.y*v1.y);
}

template <typename T>
T Vector3<T>::angle(Vector3<T> v1)
{
    return atan2(v1.y, v1.x);
}

template <typename T>
T Vector3<T>::dot(Vector3<T> v1, Vector3<T> v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

template <typename T>
T Vector3<T>::cross(Vector3<T> v1, Vector3<T> v2)
{
    return v1.x*v2.y - v1.y*v2.x;
}