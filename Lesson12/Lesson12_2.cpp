// Lesson 12 2
#include <iostream>

enum class SortingDirection { ByRows, ByColumn };

const int ROWS = 5;
const int COLUMNS = 10;

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    // idx of greater element
    int pointerIdx = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            pointerIdx++;

            // swap element at i with element at j
            std::swap(array[pointerIdx], array[j]);
        }
    }

    std::swap(array[pointerIdx + 1], array[high]);

    return (pointerIdx + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(array, low, high);
        quickSort(array, low, partition_idx - 1);
        quickSort(array, partition_idx + 1, high);
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection sd)
{
    int arrByCol[ROWS];
    if (sd == SortingDirection::ByRows) {
        for (int i = 0; i < COLUMNS; i++) {
            quickSort(arr[i], 0, COLUMNS-1);
        }
    }
    else {
        for (int i = 0; i < COLUMNS; i++) {
            for (int j = 0; j < ROWS; j++) {
                arrByCol[j] = arr[j][i];
            }

            quickSort(arrByCol, 0, ROWS-1);

            for (int k = 0; k < ROWS; k++) {
                arr[k][i] = arrByCol[k];
            }
        }
    }
}

int main(int argc, const char* argv[]) {

    srand(time(nullptr));

    int arr[ROWS][COLUMNS];

    std::cout << "Input array: " << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            arr[i][j] = rand() % 89 + 10; // generate number from 10 to 99
            std::cout << "[" << arr[i][j] << "]";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::cout << "Sorted by rows array: " << std::endl;
    sort(arr, SortingDirection::ByRows);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << "[" << arr[i][j] << "]";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Sorted by column array: " << std::endl;
    sort(arr, SortingDirection::ByColumn);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << "[" << arr[i][j] << "]";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}