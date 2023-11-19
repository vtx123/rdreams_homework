#include <iostream>

int main()
{
    // Task 1 without errors cheking
    int fNumber = 0;
    int sNumber = 0;
    int tNumber = 0;
    int max = INT_MIN;

    std::cout << "Please enter the first number: "<< std::endl;
    std::cin >> fNumber;
    std::cout << "Please enter the second number: "<< std::endl;
    std::cin >> sNumber;
    std::cout << "Please enter the third number: "<< std::endl;
    std::cin >> tNumber;

    if (fNumber >= max) {
        max = fNumber;
    }
    if (sNumber >= max) {
        max = sNumber;
    }
    if (tNumber >= max) {
        max = tNumber;
    }

    std::cout << "The maximum number is: " << max << std::endl;

    // Task 2 without errors cheking
    int number1 = 0;
    int number2 = 0;

    std::cout << "Please enter the first number: " << std::endl;
    std::cin >> number1;
    std::cout << "Please enter the second number: " << std::endl;
    std::cin >> number2;

    std::cout << "The minimum number is: " << ((number1 <= number2) ? number1 : number2) << std::endl;

    // Task 3 without errors cheking
    int divNumber = 0;

    std::cout << "Please enter a number: " << std::endl;
    std::cin >> divNumber;

    if (divNumber % 5 == 0 && divNumber % 11 == 0) {
        std::cout << "WIN! Your number " << divNumber << " was divided by 5 and 11." << std::endl;
    }
    else {
        std::cout << "NO-O-o-o! Your number " << divNumber << " wasn't divided by 5 and 11." << std::endl;
    }

    // Task 4 without errors cheking
    int fAngle = 0;
    int sAngle = 0;
    int tAngle = 0;

    std::cout << "Please enter the first angle: " << std::endl;
    std::cin >> fAngle;
    std::cout << "Please enter the second angle: " << std::endl;
    std::cin >> sAngle;
    std::cout << "Please enter the third number: " << std::endl;
    std::cin >> tAngle;

    if ((fAngle + sAngle + tAngle) == 180 && (sAngle > 0 && sAngle > 0 && tAngle > 0)) {
        std::cout << "WIN! Your angles were build a triangle!" << std::endl;
    }
    else {
        std::cout << "NO-O-o-o! Your angles weren't build a triangle!" << std::endl;
    }

    // Task 5 without errors cheking
    enum class Month {
        JANUARY = 1,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    int month = 0;

    std::cout << "Please enter a number of month: " << std::endl;
    std::cin >> month;

    std::cout << "You enter ";
    switch (static_cast<Month>(month))
    {
    case Month::JANUARY:
        std::cout << "JANUARY";
        break;
    case Month::FEBRUARY:
        std::cout << "FEBRUARY";
        break;
    case Month::MARCH:
        std::cout << "MARCH";
        break;
    case Month::APRIL:
        std::cout << "APRIL";
        break;
    case Month::MAY:
        std::cout << "MAY";
        break;
    case Month::JUNE:
        std::cout << "JUNE";
        break;
    case Month::JULY:
        std::cout << "JULY";
        break;
    case Month::AUGUST:
        std::cout << "AUGUST";
        break;
    case Month::SEPTEMBER:
        std::cout << "SEPTEMBER";
        break;
    case Month::OCTOBER:
        std::cout << "OCTOBER";
        break;
    case Month::NOVEMBER:
        std::cout << "NOVEMBER";
        break;
    case Month::DECEMBER:
        std::cout << "DECEMBER";
        break;
    default:
        std::cout << "a wrong number, try better next time." << std::endl;
        return 0;
        break;
    }

    std::cout << " month. Good job!" << std::endl;

    // Task 6 without errors cheking
    int numberOfMonth = 0;

    std::cout << "Please enter a number of month: " << std::endl;
    std::cin >> numberOfMonth;

    switch (static_cast<Month>(numberOfMonth)) 
    {
        case Month::DECEMBER:
        case Month::JANUARY:
        case Month::FEBRUARY:
            std::cout << "Winter";
            break;
        case Month::MARCH:
        case Month::APRIL:
        case Month::MAY:
            std::cout << "Spring";
            break;
        case Month::JUNE:
        case Month::JULY:
        case Month::AUGUST:
            std::cout << "Summer";
            break;
        case Month::SEPTEMBER:
        case Month::OCTOBER:
        case Month::NOVEMBER:
            std::cout << "Autumn";
            break;
        default:
            std::cout << "You enter a wrong number, programm NOT able to recognise a season!" << std::endl;
            break;
    }

    return 0;
}
