#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

template <typename T>
class Vector3
{
    public:
        Vector3();
        Vector3(T x=0, T y=0);
        Vector3<T> add(Vector3<T> v1, Vector3<T> v2);
        Vector3<T> sub(Vector3<T> v1, Vector3<T> v2);
        Vector3<T> mul(Vector3<T> v1, T s);
        Vector3<T> mul(T s, Vector3<T> v2);
        Vector3<T> div(Vector3<T> v1, T s);
        T normalize(Vector3<T> v1);
        T norm(Vector3<T> v1);
        T len(Vector3<T> v1);
        T angle(Vector3<T> v1);
        T dot(Vector3<T> v1, Vector3<T> v2);
        T cross(Vector3<T> v1, Vector3<T> v2);

    private:
        T x = 0;
        T y = 0;
};

#include "Vector3.tpp"

#endif