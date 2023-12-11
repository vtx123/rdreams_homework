#include <iostream>

void printNaturalNumbersGoingDown(int count){
    if(count > 0){
        std::cout << count << " ";
        printNaturalNumbersGoingDown(count - 1);
    }
}

void printNaturalNumbersGoingUp(int count){
    if(count > 0){
        printNaturalNumbersGoingUp(count - 1);
        std::cout << count << " ";
    }
}
