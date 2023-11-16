#include <iostream>

int main()
{
    std::cout << "I love C++!\n";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}