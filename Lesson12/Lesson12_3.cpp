// Lesson 12 3
#include <iostream>

// ANSWER: Best case = O(1). Average = worst = O(log(n)), n = size = COLUMNS = 30
// code will run 1 or 5 times
// Space complexity = 12-28 byte = from 8 + 4 to 8 + 4 * 5
bool binarySearch(int arr[], int size, int x)
{
    int l = 0; // 4 byte
    int r = size - 1; // 4 byte

    while (l <= r) {
        const int m = l + (r - l) / 2; // 4 byte

        if (arr[m] == x)
            return true;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
}

// ??? Evaluate algorithmic complexity of this program

// ANSWER: binarySearch function will run 1-20 times.
// Code inside binarySearch function will run:
// Best case = 1 * 1 = 1 times = O(1)
// Worst case = 20 * 5 = 100 times = O(r * log(c)), r = ROWS, c = COLUMNS.
// Space complexity 2424-2972 byte = from 2412 + 12 byte to 2412 + 28 * 20
int main()
{
    const int ROWS = 20; // 4 byte
    const int COLUMNS = 30; // 4 byte
    int arr[ROWS][COLUMNS] = {}; // 20*30*4 = 2400 byte
    const int toFind = 0; // 4 byte

    //...
    //Code to setup array and value to find
    //in one way or another
    //..

    for (int i = 0; i < ROWS; i++) // ANSWER: best O(1), worst O(n), n = ROWS = 20. Code will run 1-20 times
    {
        if (binarySearch(arr[i], COLUMNS, toFind)) // 12-28 byte
        {
            std::cout << "FOUND";
            break;
        }
    }
}
