// Lesson 11 1
#include <iostream>

const int COLUMNS = 10;
const int ROWS = 5;

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(arr_2d[i][j] == toFind){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr_2d[ROWS][COLUMNS];
    int userNumber = 0;

    std::srand(std::time(nullptr));

    std::cout << "Find number in Array: " << std::endl;
    for(int i = 0; i < ROWS; i++){ // initialize array
        for(int j = 0; j < COLUMNS; j++){
            arr_2d[i][j] = (std::rand() % 99) + 1; // generate random number from 1 to 99
            std::cout << "[" << arr_2d[i][j] << "] ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cin >> userNumber;

    std::cout << "Output: " << std::boolalpha << find(arr_2d, userNumber) << std::endl;
    return 0;
}
