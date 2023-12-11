// Lesson 12 3
#include <iostream>

// ANSWER: Best case = O(1). Average = worst = O(log(n)), n = size = COLUMNS = 30
// code will run 1 or 5 times
bool binarySearch(int arr[], int size, int x)
{
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        const int m = l + (r - l) / 2;

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
int main()
{
    const int ROWS = 20;
    const int COLUMNS = 30;
    int arr[ROWS][COLUMNS] = {};
    const int toFind = 0;

    //...
    //Code to setup array and value to find
    //in one way or another
    //..

    for (int i = 0; i < ROWS; i++) // ANSWER: best O(1), worst O(n), n = ROWS = 20. Code will run 1-20 times
    {
        if (binarySearch(arr[i], COLUMNS, toFind))
        {
            std::cout << "FOUND";
            break;
        }
    }
}
