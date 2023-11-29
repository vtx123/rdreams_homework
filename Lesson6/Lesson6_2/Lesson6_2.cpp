// Issue 2 - Fibonacci counter.

#include <iostream>

int main()
{
    int fibNumber = 0;

    std::cout << "Fibonacci counter!" << std::endl;
    std::cout << "Please enter the position of Fibonacci number:" << std::endl;
    std::cin >> fibNumber;
    
    if (fibNumber < 0) {
        std::cout << "ERROR: You may enter only positive number..." << std::endl;
        return 0;
    }
    
    int prevRes = 0;
    int curRes = 1;
    int nextRes = 1;

    for (int i = 0; i < fibNumber - 1; i++) {
        nextRes = curRes + prevRes;
        prevRes = curRes;
        curRes = nextRes;
    }
    std::cout << "Result: " << ((fibNumber == 0) ? 0 : curRes) << " " << std::endl;

    return 0;
}
