#include <iostream>
#include "Vector2d.h"

int main()
{
    Vector2d testVec{ 1.2f, 5.6f };
    std::cout << testVec << std::endl;

    Vector2d* v2d0 = new Vector2d();
    std::cout << *v2d0 << std::endl;

    Vector2d* v2d1 = new Vector2d(1.1f, 2.2f);
    Vector2d* v2d2 = new Vector2d(5.1f, 6.2f);
    Vector2d v2d3 = Vector2d(5.1f, 6.2f);
    Vector2d v2d4 = Vector2d(0.1f, 0.2f);

    v2d4 = v2d4 - *v2d1;
    std::cout << v2d4 << std::endl;

    v2d3 = v2d3 - *v2d2;
    std::cout << v2d3 << std::endl;
    std::cout << v2d3() << std::endl;
    std::cout << v2d3[0] << std::endl;
    std::cout << v2d3[1] << std::endl;
    
    std::cout << *v2d1 << std::endl;
    v2d1 = v2d2;
    std::cout << *v2d1 << std::endl;

    Vector2d v1 = Vector2d(3.3f, 4.4f);
    Vector2d v2 = Vector2d(1.1f, 2.2f);
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    Vector2d dif = v1 - v2;
    Vector2d sum = v1 + v2;
    std::cout << dif << std::endl;
    std::cout << sum << std::endl;

    std::cout << Vector2d::instanceCount() << std::endl;

    std::cin >> sum;
    std::cout << sum << std::endl;

}
