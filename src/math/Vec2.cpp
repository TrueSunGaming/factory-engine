#include "Vec2.hpp"
#include <cmath>

template <class T> Vec2<T>::Vec2() : x(0), y(0) {}
template <class T> Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}
template <class T> template <class F> Vec2<T>::Vec2(const Vec2<F>& other) : x(other.x), y(other.y) {}

template <class T> Vec2<T> Vec2<T>::operator + (const Vec2<T>& other) const {
    return Vec2(x + other.x, y + other.y);
}

template <class T> Vec2<T>& Vec2<T>::operator += (const Vec2<T>& other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <class T> Vec2<T> Vec2<T>::operator - (const Vec2<T>& other) const {
    return Vec2(x - other.x, y - other.y);
}

template <class T> Vec2<T>& Vec2<T>::operator -= (const Vec2<T>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template <class T> Vec2<T> Vec2<T>::operator * (T scalar) const {
    return Vec2(x * scalar, y * scalar);
}

template <class T> Vec2<T> Vec2<T>::operator * (const Vec2<T>& other) const {
    return Vec2(x * other.x, y * other.y);
}

template <class T> Vec2<T>& Vec2<T>::operator *= (T scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

template <class T> Vec2<T>& Vec2<T>::operator *= (const Vec2<T>& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

template <class T> Vec2<T> Vec2<T>::operator / (T scalar) const {
    return Vec2(x / scalar, y / scalar);
}

template <class T> Vec2<T> Vec2<T>::operator / (const Vec2<T>& other) const {
    return Vec2(x / other.x, y / other.y);
}

template <class T> Vec2<T>& Vec2<T>::operator /= (T scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

template <class T> Vec2<T>& Vec2<T>::operator /= (const Vec2<T>& other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

template <class T> bool Vec2<T>::operator == (const Vec2<T>& other) const {
    return x == other.x && y == other.y;
}

template <class T> bool Vec2<T>::operator != (const Vec2<T>& other) const {
    return !(*this == other);
}

template <class T> Vec2<T>& Vec2<T>::operator = (const Vec2<T>& other) {
    x = other.x;
    y = other.y;

    return *this;
}

template <class T> T Vec2<T>::magnitudeSquared() const {
    return x * x + y * y;
}

template <class T> T Vec2<T>::magnitude() const {
    return sqrt(magnitudeSquared());
}

template <class T> T Vec2<T>::distanceSquared(const Vec2<T>& other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
}

template <class T> T Vec2<T>::distance(const Vec2<T>& other) const {
    return sqrt(distanceSquared(other));
}

template <class T> T Vec2<T>::dot(const Vec2<T>& other) const {
    return x * other.x + y * other.y;
}

template <class T> double Vec2<T>::originAngle() const {
    return atan2(y, x);
}

template <class T> double Vec2<T>::angle(const Vec2<T>& other) const {
    return atan2(other.y - y, other.x - x);
}

template <class T> Vec2<T>& Vec2<T>::normalize() {
    return *this /= magnitude();
}

template <class T> Vec2<T>& Vec2<T>::normalize(T length) {
    this->normalize();
    return *this *= length;
}

template <class T> Vec2<T> Vec2<T>::normalized() const {
    return *this / magnitude();
}

template <class T> Vec2<T> Vec2<T>::normalized(T length) const {
    return this->normalized() * length;
}

template <class T> Vec2<T> Vec2<T>::direction(const Vec2<T>& other) const {
    return (other - *this).normalize();
}

template <class T> Vec2<T>& Vec2<T>::rotate(double rad) {
    x = x * cos(rad) - y * sin(rad);
    y = x * sin(rad) + y * cos(rad);

    return *this;
}

template <class T> Vec2<T>& Vec2<T>::rotateDeg(double deg) {
    return rotate(deg * M_PI / 180);
}

template <class T> Vec2<T> Vec2<T>::rotated(double rad) const {
    return Vec2(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
}

template <class T> Vec2<T> Vec2<T>::rotatedDeg(double deg) const {
    return rotated(deg * M_PI / 180);
}

template <class T> Vec2<T>& Vec2<T>::moveTowards(const Vec2<T>& other, T distance) {
    return *this += direction(other) * distance;
}

template <class T> Vec2<T> Vec2<T>::movedTowards(const Vec2<T>& other, T distance) const {
    return *this + direction(other) * distance;
}

template <class T> Vec2<T>& Vec2<T>::lerp(const Vec2<T>& other, double t) {
    return *this += (other - *this) * t;
}

template <class T> Vec2<T> Vec2<T>::lerped(const Vec2<T>& other, double t) const {
    return *this + (other - *this) * t;
}

template <class T> std::string Vec2<T>::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}