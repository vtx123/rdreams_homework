// Lesson 9 Issue 5
#include <iostream>

bool isEqual(const char str1[], const char str2[]){
    unsigned lenghtStr1 = static_cast<int>(strlen(str1));
    unsigned lenghtStr2 = static_cast<int>(strlen(str2));

    if(lenghtStr1 != lenghtStr2){
        return false;
    }

    for(int i = 0; i < lenghtStr1; i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }

    return true;
}

int main() {
    std::string userInput1;
    std::string userInput2;

    std::cout << "Is two string equal? "<< std::endl;

    std::cout << "Please enter a first string: " << std::endl;
    std::getline(std::cin, userInput1);

    std::cout << "Please enter a second string: " << std::endl;
    std::getline(std::cin, userInput2);

    std::cout << "Result: " << (isEqual(userInput1.data(), userInput2.data())?"Yes, equal!":"No! Not equal.") << std::endl;

    return 0;
}
