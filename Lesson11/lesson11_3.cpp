// Lesson 11 3
#include <iostream>

const int COL = 4;
const int ROW = 4;

void passArrV1(int arr_2d[ROW][COL])
{
    std::cout << "Passing array v1: " << std::endl;
    for (int j = COL - 1; j >= 0; j--) {
        for (int i = 0; i < ROW; i++) {
            arr_2d[i][j] = 0;
            std::cout << "[" << i << ":" << j << "] ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void passArrV2(int arr_2d[ROW][COL])
{
    std::cout << "Passing array v2: " << std::endl;
    for (int i = ROW - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            for (int j = 0; j < COL; j++) {
                arr_2d[i][j] = 0;
                std::cout << "[" << i << ":" << j << "] ";
            }
        }
        else {
            for (int j = COL - 1; j >= 0; j--) {
                arr_2d[i][j] = 0;
                std::cout << "[" << i << ":" << j << "] ";
            }
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int arr_2d[ROW][COL];

    passArrV1(arr_2d);
    passArrV2(arr_2d);

    return 0;
}
