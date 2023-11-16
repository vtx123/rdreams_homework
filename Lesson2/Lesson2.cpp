#include <iostream>
#include <iomanip>

int main()
{
// Task 1 no user input check
    int a = 0;
    int b = 0;
    int swap = 0;

    std::cout << "Enter Integer 1: " << std::endl;
    std::cin >> a;
    std::cout << "Enter Integer 2: " << std::endl;
    std::cin >> b;

    swap = b;
    b = a;
    a = swap;

    std::cout << "Integer 1: " << a << std::endl;
    std::cout << "Integer 2: " << b << std::endl;

// Task 2
    double myDouble = 123.4567;
    std::cout << myDouble << std::endl;
    std::cout << static_cast<int>(myDouble) << std::endl;
    std::cout << std::setfill('$') << std::setw(20) << std::right << myDouble << std::endl;

// Task 3
    double secondDouble = 321.123456789;
    std::cout << "Double in default notation: " << std::setprecision(2) << secondDouble << std::endl;
    std::cout << "Double in standard notation: " << std::fixed << std::setprecision(5) << secondDouble << std::endl;
    std::cout << "Double in e-notation: " << std::scientific << std::setprecision(10) << secondDouble << std::endl;

// Task 4
    enum class WeekDay {
        MONDAY = 1,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
    };

    WeekDay day1 = WeekDay::MONDAY;
    WeekDay day2 = WeekDay::TUESDAY;
    WeekDay day3 = WeekDay::WEDNESDAY;
    WeekDay day4 = WeekDay::THURSDAY;
    WeekDay day5 = WeekDay::FRIDAY;
    WeekDay day6 = WeekDay::SATURDAY;
    WeekDay day7 = WeekDay::SUNDAY;

    std::cout << static_cast<int>(day1) << std::endl;
    std::cout << static_cast<int>(day2) << std::endl;
    std::cout << static_cast<int>(day3) << std::endl;
    std::cout << static_cast<int>(day4) << std::endl;
    std::cout << static_cast<int>(day5) << std::endl;
    std::cout << static_cast<int>(day6) << std::endl;
    std::cout << static_cast<int>(day7) << std::endl;

// Task 5 no user input check
    int intDigitToBool = 0;
    std::cout << "Please put an Integer number: " << std::endl;
    std::cin >> intDigitToBool;
    std::cout << std::boolalpha << static_cast<bool>(intDigitToBool) << std::endl;
}
