// Issue 4 - Print figures.

#include <iostream>

int main()
{
    int w = 0;
    int h = 0;

    std::cout << "Print figures!" << std::endl;
    std::cout << "Please enter a width:" << std::endl;
    std::cin >> w;
    std::cout << "Please enter a height:" << std::endl;
    std::cin >> h;

    if (w <= 0 || h <= 0) {
        std::cout << "ERROR: You may enter only positive number more than 0..." << std::endl;
        return 0;
    }

    if (w > 25 || h > 25) {
        std::cout << "ERROR: You may enter numbers less than 25 to avoid visual bugs." << std::endl;
        return 0;
    }

    // triangle top
    for (int i = 0; i < h; i++) {
        for (int j = i; j < w; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // triangle bottom
    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= i && j <= w; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // square
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // diagonal
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w + i + 1; j++) {
            if (i <= j) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // binary triangle
    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << (((i + j) % 2) ? "0" : "1");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}