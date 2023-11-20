// Issue 3 - Factorial counter.

#include <iostream>

int main()
{
    int facNumber = 0;
    
    std::cout << "Factorial counter!" << std::endl;
    std::cout << "Please enter a number:" << std::endl;
    std::cin >> facNumber;
    
    if (facNumber < 0) {
        std::cout << "ERROR: You may enter only positive number..." << std::endl;
        return 0;
    }

    long long factorial = 1;
    for (int i = 1; i <= facNumber; i++) {
        factorial *= i;
    }

    std::cout << "Result: " << ((facNumber == 0) ? 1 : factorial) << " " << std::endl;

    return 0;
}
