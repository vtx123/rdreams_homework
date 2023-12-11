// Lesson 9 Issue 2
#include <iostream>

void toUppercase(char str[]){
    unsigned lenght = static_cast<int>(strlen(str));

    for(int i = 0; i < lenght; i++){
        if (islower(str[i])) {
            std::cout << static_cast<char>(toupper(str[i]));
        }else {
            std::cout << str[i];
        }
    }
}

int main() {
    std::string userInput;

    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, userInput);

    std::cout << "Result: ";
    toUppercase(userInput.data());
    std::cout << std::endl;

    return 0;
}
