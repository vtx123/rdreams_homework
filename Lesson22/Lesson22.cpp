// Lesson 22

#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicArray<float> arr1;
    arr1.reserve(15);
    DynamicArray<int> arr2 = DynamicArray<int>(10);

    arr1.push_back(1.1f);
    arr1.push_back(1.2f);
    arr1.push_back(1.3f);

    std::cout << "arr 1: " << std::endl;
    for (int i = 0; i < arr1.getSize(); i++) {
        std::cout << "[" << arr1[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "arr 2: " << std::endl;
    const size_t arr2Size = arr2.getCapacity();
    for (int i = 0; i < arr2Size; i++) {
        arr2.push_back(i);
        std::cout << "[" << arr2[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    const int arr2NewSize = 21;
    arr2.setSize(arr2NewSize);
    arr2.push_back(20);
    arr2.shrinkToFit();
    std::cout << "arr 2++: " << std::endl;
    for (int i = 0; i < arr2NewSize; i++) {
        std::cout << "[" << arr2[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    DynamicArray<float> arr3(arr1);
    const size_t arr4Size = arr3.getSize();
    std::cout << "arr 3: " << std::endl;
    for (int i = 0; i < arr4Size; i++) {
        std::cout << "[" << arr3[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    arr3.push_back(100);
    arr3.push_back(300);

    std::cout << "arr 3++: " << std::endl;
    for (int i = 0; i < arr3.getSize(); i++) {
        std::cout << "[" << arr3[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    arr3.pop_back();
    std::cout << "arr 3-: " << std::endl;
    for (int i = 0; i < arr3.getSize(); i++) {
        std::cout << "[" << arr3[i] << "] ";
    }
    std::cout << std::endl << "arr3, last element = " << arr3.back() << std::endl << std::endl;

    DynamicArray<float> a1;
    a1.push_back(1.1f);
    a1.push_back(1.2f);
    a1.push_back(1.3f);

    DynamicArray<float> a2;
    a2.push_back(1.3f);
    a2.push_back(2.2f);
    a2.push_back(3.1f);
    std::cout << std::endl << "Compare arrays(arr1 and a1): " << std::endl;
    for (int i = 0; i < arr1.getSize(); i++) {
        std::cout << "[" << arr1[i] << "] ";
    }
    std::cout << "and" << std::endl;
    for (int i = 0; i < a1.getSize(); i++) {
        std::cout << "[" << a1[i] << "] ";
    }
    std::cout << ((arr1 == a1) ? "Equal " : "NOT Equal") << std::endl << std::endl;

    std::cout << "Compare arrays(a1 and a2): " << std::endl;
    for (int i = 0; i < a1.getSize(); i++) {
        std::cout << "[" << a1[i] << "] ";
    }
    std::cout << "and" << std::endl;
    for (int i = 0; i < a2.getSize(); i++) {
        std::cout << "[" << a2[i] << "] ";
    }
    std::cout << ((a1 == a2)?"Equal ":"NOT Equal") << std::endl << std::endl;

    return 0;
}