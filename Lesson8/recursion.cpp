#include <iostream>
#include "recursion.hpp"

void printNaturalNumbersGoingDown(int count){
    if(count > 0){
        std::cout << count << " ";
        printNaturalNumbersGoingDown(--count);
    }
}

void printNaturalNumbersGoingUp(int count){
    if(count > 0){
        printNaturalNumbersGoingUp(--count);
        std::cout << count+1 << " ";
    }
}
