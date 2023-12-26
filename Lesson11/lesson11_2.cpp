// Lesson 11 2
#include <iostream>

const int SIZE = 30;
enum class SortingDirection { ascending, descending };

bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                return false;
            }
        }
    }
    else {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] <= arr[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int arr[SIZE];

    std::srand(std::time(nullptr));

    for (int n = 0; n < 3; n++) { // initialize and check input array twice(ascending and descending)
        std::cout << "Is array sorted?" << std::endl;
        for (int i = 0; i < SIZE; i++) {
            if (n == 0) { // ascending initialization
                arr[i] = i + 1;
            }
            else if (n == 1) { // descending initialization
                arr[i] = SIZE - i;
            }
            else {
                arr[i] = rand() % 10 + 1; // random initialization from 1 to 10
            }

            std::cout << "[" << arr[i] << "] ";
        }
        std::cout << std::endl;

        std::cout << "By ascending: " << std::boolalpha << isSorted(arr, SIZE, SortingDirection::ascending) << std::endl;
        std::cout << "By descending: " << std::boolalpha << isSorted(arr, SIZE, SortingDirection::descending) << std::endl << std::endl;
    }

    return 0;
}
