// Issue 5 - Checking symbol.
#include <iostream>

int main()
{
    char symbol = ' ';
    int sum = 0;
    int overflowCheck = 0;
    const int maxChar = 127;

    while (true) {
        std::cout << "Please enter one symbol ['.' for exit]: " << std::endl;
        std::cin >> symbol;

        if (iscntrl(symbol) || isblank(symbol) || isspace(symbol)) {
            std::cout << "This symbol is not processing... Try Again." << std::endl;
        }

        if (ispunct(symbol)) {
            if (symbol == '.') {
                std::cout << "Good bye!" << std::endl;
                return 0;
            }
            std::cout << "This symbol is not processing... Try Again." << std::endl;
        }

        if (islower(symbol)) {
            std::cout << static_cast<char>(toupper(symbol)) << std::endl;
        }

        if (isdigit(symbol)) {
            overflowCheck = static_cast<int>(symbol - '0');
            if ((overflowCheck + sum) > maxChar) {
                sum = 0;
                std::cout << "AhtunG!!! char owerflow! Now sum is: " << sum << std::endl;
            }
            else {
                sum += symbol - '0';
                std::cout << "Sum is: " << sum << std::endl;
            }
        }
    }

    return 0;
}