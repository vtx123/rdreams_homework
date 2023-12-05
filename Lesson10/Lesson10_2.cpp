// Lesson 10 2
#include <iostream>

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if(arrSize <= 0){
        return false;
    }

    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
    }
    return true;
}

int main() {
    int arraySize = 0;
    double sum = 0;

    std::cout << "Please, enter an array size: " <<std::endl;
    std::cin >> arraySize;

    double inputArray[arraySize];
    for(int i = 0; i < arraySize; i++){
        std::cin >> inputArray[i];
    }

    std::cout << "Output: " << std::boolalpha <<calculateSum(inputArray, arraySize, sum) << " Sum: " << sum << std::endl;
    return 0;
}
