// Lesson 9 Issue 3
#include <iostream>

bool isPalindrom(const char str[]){
    unsigned length = static_cast<int>(strlen(str));

    for(int i = 0; i < length/2; i++){
        if(str[i] != str[length - i - 1]){
            return false;
        }
    }
    return true;
}

int main() {
    std::string userInput;

    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, userInput);

    std::cout << "Output: " << std::boolalpha << isPalindrom(userInput.data()) << std::endl;

    return 0;
}
