#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray arr1;
    DynamicIntArray arr2 = DynamicIntArray(10);

    const int arr1NewSize = 5;
    arr1.setSize(arr1NewSize);
    const int arr1Size = arr1.getSize();
    for (int i = 0; i < arr1Size; i++) {
        arr1.push_back(i * 10);
        std::cout << "[" << arr1[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    const int arr2Size = arr2.getSize();
    for (int i = 0; i < arr2Size; i++) {
        arr2.push_back(i);
        std::cout << "[" << arr2[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    const int arr2NewSize = 15;
    arr2.setSize(arr2NewSize);
    for (int i = 0; i < arr2NewSize; i++) {
        arr2.push_back(i + 10);
        std::cout << "[" << arr2[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    DynamicIntArray arr3(arr1);
    const int arr4Size = arr3.getSize();
    for (int i = 0; i < arr4Size; i++) {
        std::cout << "[" << arr3[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    arr3.push_back(100);
    arr3.push_back(300);

    for (int i = 0; i < arr3.getSize(); i++) {
        std::cout << "[" << arr3[i] << "] ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}