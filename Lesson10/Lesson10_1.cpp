// Lesson 10 1
#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int* a, int* b) {
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Please, enter a first number: " << std::endl;
    std::cin >> a;
    std::cout << "Please, enter a second number: " << std::endl;
    std::cin >> b;

    std::cout << "Output 1 swap ref:" << std::endl;
    std::cout << "before swap ref: " << a << " " << b << std::endl;
    std::cout << "before swap ref: " << &a << " " << &b << std::endl;
    swap(a, b);
    std::cout << "after swap ref: " << a << " " << b << std::endl;
    std::cout << "after swap ref: " << &a << " " << &b << std::endl << std::endl;

    std::cout << "Output 2 swap ptr:" << std::endl;
    std::cout << "before swap ptr: " << a << " " << b << std::endl;
    std::cout << "before swap ptr: " << &a << " " << &b << std::endl;
    swap(&a, &b);
    std::cout << "after swap ptr: " << a << " " << b << std::endl;
    std::cout << "after swap ptr: " << &a << " " << &b << std::endl;
    return 0;
}
