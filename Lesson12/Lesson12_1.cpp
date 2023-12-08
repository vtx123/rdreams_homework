// Lesson 12 1
#include <iostream>

void bubbleSort(int arr[], int size){
    int tmp = 0;

    for(int n = 0; n < size - 1; n++){
        for(int i = 0; i < size - 1 - n; i++)
        {
            if(arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }

    std::cout << "Bubble sorted array: "<< std::endl;
    for(int i = 0; i < size; i++){
        std::cout << "[" << arr[i] << "]";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    srand(time(nullptr));

    const int size = 20;
    int arr[size];

    std::cout << "Input array: " << std::endl;
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 99 + 1; // generate number from 1 to 99
        std::cout << "[" << arr[i] << "]";
    }
    std::cout << std::endl << std::endl;

    bubbleSort(arr, size);

    return 0;
}