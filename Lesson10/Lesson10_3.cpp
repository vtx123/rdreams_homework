// Lesson 10 3
#include <iostream>

bool find(const int* arr, int size, int elem) {
    for(int i = 0; i < size; i++){
        if(*(arr + i) == elem){
            return true;
        }
    }
    return false;
}

int main() {
    const int arraySize = 10;
    int inputArray[arraySize];
    int userNumber = 0;

    std::srand(std::time(nullptr));

    std::cout << "Find number in Array: ";
    for(int i = 0; i < arraySize; i++){ // initialize array
        *(inputArray + i) = (std::rand() % 100) + 1; // generate random number from 1 to 99
        std::cout << "[" << *(inputArray + i) << "] ";
    }
    std::cout << std::endl;

    std::cin >> userNumber;

    std::cout << "Output: " << std::boolalpha << find(inputArray, arraySize, userNumber) << std::endl;
    return 0;
}
