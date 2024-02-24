#include <string>
#include "../macros.hpp"

#ifndef FE_VEC2_HPP
#define FE_VEC2_HPP

template <class T> class DLL_EXPORT Vec2 {
    public:
        T x, y;

        DLL_EXPORT Vec2();
        DLL_EXPORT Vec2(T x, T y);
        template <class F> DLL_EXPORT Vec2(const Vec2<F>& other);

        DLL_EXPORT Vec2<T> operator + (const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& operator += (const Vec2<T>& other);
        DLL_EXPORT Vec2<T> operator - (const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& operator -= (const Vec2<T>& other);
        DLL_EXPORT Vec2<T> operator * (T scalar) const;
        DLL_EXPORT Vec2<T> operator * (const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& operator *= (T scalar);
        DLL_EXPORT Vec2<T>& operator *= (const Vec2<T>& other);
        DLL_EXPORT Vec2<T> operator / (T scalar) const;
        DLL_EXPORT Vec2<T> operator / (const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& operator /= (T scalar);
        DLL_EXPORT Vec2<T>& operator /= (const Vec2<T>& other);
        DLL_EXPORT bool operator == (const Vec2<T>& other) const;
        DLL_EXPORT bool operator != (const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& operator = (const Vec2<T>& other);

        DLL_EXPORT T magnitudeSquared() const;
        DLL_EXPORT T magnitude() const;
        DLL_EXPORT T distanceSquared(const Vec2<T>& other) const;
        DLL_EXPORT T distance(const Vec2<T>& other) const;
        DLL_EXPORT T dot(const Vec2<T>& other) const;
        DLL_EXPORT double originAngle() const;
        DLL_EXPORT double angle(const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& normalize();
        DLL_EXPORT Vec2<T>& normalize(T length);
        DLL_EXPORT Vec2<T> normalized() const;
        DLL_EXPORT Vec2<T> normalized(T length) const;
        DLL_EXPORT Vec2<T> direction(const Vec2<T>& other) const;
        DLL_EXPORT Vec2<T>& rotate(double rad);
        DLL_EXPORT Vec2<T>& rotateDeg(double deg);
        DLL_EXPORT Vec2<T> rotated(double rad) const;
        DLL_EXPORT Vec2<T> rotatedDeg(double deg) const;
        DLL_EXPORT Vec2<T>& moveTowards(const Vec2<T>& other, T distance);
        DLL_EXPORT Vec2<T> movedTowards(const Vec2<T>& other, T distance) const;
        DLL_EXPORT Vec2<T>& lerp(const Vec2<T>& other, double t);
        DLL_EXPORT Vec2<T> lerped(const Vec2<T>& other, double t) const;
        DLL_EXPORT std::string toString() const;
};

template class Vec2<float>;
template class Vec2<double>;
template class Vec2<int>;
template class Vec2<unsigned int>;
template class Vec2<long>;
template class Vec2<unsigned long>;

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;
typedef Vec2<unsigned int> Vec2u;
typedef Vec2<long> Vec2l;
typedef Vec2<unsigned long> Vec2ul;

#endif