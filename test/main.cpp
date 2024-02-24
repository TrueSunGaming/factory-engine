#include "../src/math/Vec2.hpp"
#include <iostream>

int main() {
    Vec2d v1 = Vec2d(100, 100);

    v1 += Vec2d(100, 50);

    v1.normalize();

    std::cout << v1.x << " " << v1.y << std::endl;
}