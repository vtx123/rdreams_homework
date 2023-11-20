// Issue 1 - Arithmetic progression.

#include <iostream>

int main()
{
    int firstElement = 0;
    int step = 0;
    int lastElement = 0;

    std::cout << "Arithmetic progression!" << std::endl;
    std::cout << "Please enter the first element of progression:" << std::endl;
    std::cin >> firstElement;
    std::cout << "Please enter a step of progression:" << std::endl;
    std::cin >> step;
    std::cout << "Please enter the last element of progression:" << std::endl;
    std::cin >> lastElement;

    if (lastElement < firstElement) {
        std::cout << "Ohhh NO! Your last element lower than the first element of progression!";
    }

    int nextElementOfProgression = firstElement;

    while (nextElementOfProgression <= lastElement) {
        std::cout << nextElementOfProgression << " ";
        nextElementOfProgression += step;
    }

    std::cout << std::endl;
}