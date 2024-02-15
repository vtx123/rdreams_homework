// Lesson 26

#include <iostream>
#include "Vector2d.h"

int main()
{
    Vector2d v2d_1{ 1.0f, 1.0f, 3.0f, 4.0f };

    Vector2d v2d_2{ 1.0f, 2.0f};
    Vector2d v2d_3{ 3.0f, 4.0f };
    std::cout << "Dot Product = " << v2d_2.dotProduct(v2d_3) << std::endl;
    std::cout << "Inversion = " << v2d_2 << " transform to " << v2d_2.negate() << std::endl << std::endl;

    Vector2d v1{ 1.0f, 2.0f };
    Vector2d v2{ 2.0f, -1.0f };
    Vector2d v3{ -1.0f, -2.0f };
    Vector2d v4{ 2.0f, 3.0f };

    std::cout << "--- Relative State Test --- " << std::endl;
    std::cout << relativeToStr(v1.getRelativeState(v1)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState(v2)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState(v3)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState(v4)) << std::endl << std::endl;

    std::cout << relativeToStr(v1.getRelativeState2(v1)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState2(v2)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState2(v3)) << std::endl;
    std::cout << relativeToStr(v1.getRelativeState2(v4)) << std::endl << std::endl;

    std::cout << "Scale = " << v2d_3 << " transform to ";
    v2d_3.scale(2.0f, 2.0f);
    std::cout << v2d_3 << std::endl;

    Vector3d vec3_1 = Vector3d(1.0f, 2.0f, 3.0f);
    Vector3d vec3_2 = Vector3d(4.0f, 5.0f, 6.0f);

    std::cout << "Cross Product = " << vec3_1.crossProduct(vec3_2) << std::endl;
}
