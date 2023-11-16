#include <iostream>

int main()
{
    // Task 1 without checking errors
    unsigned int amountOfSecond = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    std::cout << "Please enter amount of seconds: " << std::endl;
    std::cin >> amountOfSecond;

    hours = amountOfSecond / 3600;
    minutes = (amountOfSecond - hours * 3600) / 60;
    seconds = amountOfSecond - hours * 3600 - minutes * 60;

    std::cout << "Result: ";
    if (hours > 1) {
        std::cout << hours << " hours, ";
    }
    else {
        std::cout << hours << " hour, ";
    }

    if (minutes > 1) {
        std::cout << minutes << " minutes, ";
    }
    else {
        std::cout << minutes << " minute, ";
    }

    if (seconds > 1) {
        std::cout << seconds << " seconds." << std::endl;
    }
    else {
        std::cout << seconds << " second." << std::endl;
    }

    // Task 2 without checking errors
    int firstNumber = 0;
    int secondNumber = 0;
    int thirdNumber = 0;

    std::cout << "Please enter the first number: " << std::endl;
    std::cin >> firstNumber;

    std::cout << "Please enter the second number: " << std::endl;
    std::cin >> secondNumber;

    std::cout << "Please enter the third number: " << std::endl;
    std::cin >> thirdNumber;

    std::cout << "Sum of three numbers: " << firstNumber + secondNumber + thirdNumber << std::endl;
    std::cout << "Product of three numbers: " << firstNumber * secondNumber * thirdNumber << std::endl;
    std::cout << "Arithmetic of three numbers: " << (firstNumber + secondNumber + thirdNumber) / 3 << std::endl;

    std::cout << "First number " << firstNumber;
    if (firstNumber > secondNumber) {
        std::cout << " BIGGER than";
    }
    else if (firstNumber < secondNumber) {
        std::cout << " SMALLER than";
    }
    else {
        std::cout << " EQUAL to";
    }
    std::cout << " second number " << secondNumber << std::endl;

    // Task 3 without checking errors
    int firstNum = 0;
    int secondNum = 0;

    std::cout << "Please enter the first number: " << std::endl;
    std::cin >> firstNum;

    std::cout << "Please enter the second number: " << std::endl;
    std::cin >> secondNum;

    bool lessThan = firstNum < secondNum;
    bool equal = firstNum == secondNum;
    bool moreThan = firstNum > secondNum;
    bool lessOrEqual = firstNum <= secondNum;

    std::cout << std::boolalpha << "Result: " << "lessThan " << lessThan;
    std::cout << ", equal " << equal;
    std::cout << ", moreThan " << moreThan;
    std::cout << ", lessOrEqual " << lessOrEqual << std::endl;

    // Task 4 without checking errors
    int width = 0;
    int height = 0;

    std::cout << "Please enter the width: " << std::endl;
    std::cin >> width;

    std::cout << "Please enter the height: " << std::endl;
    std::cin >> height;

    std::cout << "Area: " << width * height << std::endl;
    std::cout << "Perimeter: " << (width + height) * 2 << std::endl;

    // Task 5 without checking errors, math.h and iomanip
    int radius = 0;
    const double pi = 3.1415926;

    std::cout << "Please enter the radius: " << std::endl;
    std::cin >> radius;

    std::cout << "Area: " << pi * radius * radius << std::endl;
    std::cout << "Perimeter: " << 2 * pi * radius << std::endl;
}