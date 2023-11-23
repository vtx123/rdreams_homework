#include <iostream>
#include "loop.hpp"

void printNaturalNumbersLoopGoingDown(int count){
    for(int i = count; i > 0; i--){
        std::cout << i << " ";
    }
}

void printNaturalNumbersLoopGoingUp(int count){
    for(int i = 1; i <= count; i++){
        std::cout << i << " ";
    }
}
