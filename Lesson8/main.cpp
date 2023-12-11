#include <iostream>
#include "recursion.hpp"
#include "loop.hpp"

// Issue 1
void inputCouter(int amoutOfInput){
    int userInput = 0;
    int positivesCounter = 0;
    int negativesCounter = 0;
    int zeroesCounter = 0;

    std::cout<< "You need enter " << amoutOfInput << " numbers." << std::endl;
    for(int i = 0; i < amoutOfInput; i++){
        std::cout<< "Your " << i+1 << " number is: " << std::endl;
        std::cin >> userInput;

        if(userInput < 0){
            negativesCounter++;
        } else if(userInput > 0){
            positivesCounter++;
        } else {
            zeroesCounter++;
        }
    }

    std::cout << "Output: ";
    std::cout << "Positive: " << positivesCounter;
    std::cout << ", negative: " << negativesCounter;
    std::cout << ", zeroes: " << zeroesCounter << std::endl;
}

// Issue 2
long long factorial(long long count) {
    if(count == 0){
        return 1;
    }
    return factorial(count - 1) * count;
}

int main()
{
    long long f = 0;
    int N;

    //issue 1
    inputCouter(5);

    // issue 2
    std::cout << "Enter a number for counting FACTORIAL: " << std::endl;
    std::cin >> f;
    if(f >= 19 ){
        std::cout << "You number too much BIG to countig factorial, try next time ;(" << std::endl;
    }
    std::cout << "Factorial:" << factorial(f) << std::endl;

    // issue 3, 4
    std::cout << "Please enter a number: " << std::endl;
    std::cin >> N;

    std::cout << "Recursion sequence DOWN: "<< std::endl;
    printNaturalNumbersGoingDown(N);
    std::cout << std::endl << std::endl;

    std::cout << "Recursion sequence UP: "<< std::endl;
    printNaturalNumbersGoingUp(N);
    std::cout << std::endl << std::endl;

    std::cout << "Loop sequence DOWN: "<< std::endl;
    printNaturalNumbersLoopGoingDown(N);
    std::cout << std::endl << std::endl;

    std::cout << "Loop sequence UP: "<< std::endl;
    printNaturalNumbersLoopGoingUp(N);
    std::cout << std::endl << std::endl;

    return 0;
}
