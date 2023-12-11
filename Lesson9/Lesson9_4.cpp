// Lesson 9 Issue 4
#include <iostream>

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount){
    unsigned lenght = static_cast<int>(strlen(str));

    for(int i = 0; i < lenght; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
           str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
           str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
           str[i] == 'U') {
            vowelsCount++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            consonantsCount++;
        }
    }
}

int main() {
    int vowelsCount = 0;
    int consonantsCount = 0;

    std::string userInput;

    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, userInput);

    parseStringLetters(userInput.data(), vowelsCount, consonantsCount);
    std::cout << "Output: " << std::endl;
    std::cout << "Vowels: " << vowelsCount << std::endl;
    std::cout << "Consonants: " << consonantsCount << std::endl;

    return 0;
}

