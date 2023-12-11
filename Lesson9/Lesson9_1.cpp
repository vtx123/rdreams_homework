// Lesson 9 Issue 1
#include <iostream>

void translateArray(int numbers[], int size){
    for(int i = 0; i < size; i++){
        if(numbers[i] > 0){
            numbers[i] *= 2;
        }else {
            numbers[i] = 0;
        }

        std::cout << numbers[i] << " ";
    }
}

int main() {
    const int arraySize = 10;
    int array[arraySize];
    std::string userInput;
    std::string subString;

    size_t prevPos = 0;
    size_t nextPos = 0;
    int i = 0;

    for(int i = 0; i < arraySize; i++){ // initialize output array
        array[i] = 0;
    }

    std::cout << "Please enter an 10 digit" << std::endl;
    std::getline(std::cin, userInput);

    while((nextPos = userInput.find(" ", prevPos)) != std::string::npos && i < arraySize){
        subString = userInput.substr(prevPos, nextPos - prevPos);
        prevPos = nextPos + 1;

        if(subString == ""){
            continue;
        }

        array[i] = stoi(subString);
        i++;
    }
    std::cout << "Result: ";
    translateArray(array, arraySize);
    std::cout << std::endl;

    return 0;
}

