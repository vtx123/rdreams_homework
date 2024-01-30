#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class LengthComparator
{
public:
    bool operator() (const std::string& str1, const std::string& str2) const
    {
        return str1.length() < str2.length();
    }
};

bool compareByLength(const std::string& str1, const std::string& str2)
{
    return str1.length() > str2.length();
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{

    return std::count_if(vec.begin(), vec.end(), [number](int element)
        {
            return element % number == 0;
        }
    );
}

int main()
{
    srand(time(nullptr));
    std::vector<std::string> stringContainer;

    auto randomSymbol = []() // generate random symbol
    {
        const char alfabet[] = "abcdefghijklmnopqrstuvwxyz";
        const size_t lastIndex = (sizeof(alfabet) - 1);
        return alfabet[rand() % lastIndex];
    };

    std::cout << "--- Generate random string ---" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        size_t length = 2 + rand() % 13;
        std::string str(length, 0);
        std::generate_n(str.begin(), length, randomSymbol);
        stringContainer.push_back(str);

        std::cout << str << std::endl;
    }

    std::cout << std::endl << "--- Sorting string with function ---" << std::endl;
    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    for (const auto& s : stringContainer)
    {
        std::cout << s << std::endl;
    }

    std::cout << std::endl << "--- Sorting string with class ---" << std::endl;
    LengthComparator lComparator;
    std::sort(stringContainer.begin(), stringContainer.end(), lComparator);
    for (const auto& s : stringContainer)
    {
        std::cout << s << std::endl;
    }

    std::cout << std::endl << "--- Sorting string with lambda ---" << std::endl;
    std::sort(stringContainer.begin(), stringContainer.end(),
        [](const std::string& str1, const std::string& str2)
        {
            return str1.length() > str2.length();
        });
    for (const auto& s : stringContainer)
    {
        std::cout << s << std::endl;
    }

    std::cout << std::endl << "--- How much elements of vector divisible by Number ---" << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    std::cout << countDivisibleBy(vec, 5) << std::endl;
}