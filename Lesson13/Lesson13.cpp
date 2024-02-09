#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>

// small vacabulary from https://copylists.com/words/list-of-5-letter-words/
// middle vacabulary from https://github.com/charlesreid1/five-letter-words/blob/master/sgb-words.txt
// need encript the save file to prevent hacking/cheeting guessing words
// need store save file on a server or at least dobling time variable in windows's registry to prevent time cheeting
// program works correctly ONLY on WINDIWS machine

static const bool QA_MODE = true; // shows hidden tips :)
static const unsigned long long secondsMinutesHours = 86400;
static const unsigned long long nanoseconds = 10000000;
static const std::string saveFileName = "save.ini";
static const std::string dictionaryFileName = "words.txt";
static unsigned long long timeForDailyGame = 0;

enum GameState {
    INIT = 1,
    MENU,
    RANDOM_GAME_MODE,
    DAILY_GAME_MODE,
    EXIT
};

void caesarsEncript() {
    // enctipt the word before save it into readable file
}

void caesarsDecript() {
    // decript the word after reading from visually unsafe file
}

void loadDictionaryFromFile(std::vector<std::string>& dictionary) {
    std::ifstream iFile(dictionaryFileName);


    if (iFile.is_open()) { // read dictionary file
        std::string line;

        while (getline(iFile, line)) {
            std::transform(line.begin(), line.end(), line.begin(), ::toupper);
            dictionary.push_back(line);
        }
        iFile.close();
    }
}

bool tryToLoadSavedGamesFromFile() {
    std::ifstream iFile(saveFileName);
    if (iFile.is_open()) { 
        iFile.close();
        return true;
    }
    else {
        return false;
    }
}

std::string loadFromFile(std::vector<std::string>& dictionary) {
    std::ifstream iFile(saveFileName);
    std::string wordOfTheDay;
    unsigned long long timeFromFile;

    if (iFile.is_open()) { // read user data file
        std::string line;

        getline(iFile, line);
        wordOfTheDay = line;

        getline(iFile, line);
        timeFromFile = std::stoull(line);

        iFile.close();
    }
    else {
        std::cout << "I couldn't open File. Something went WRONG please text to developers!" << std::endl;
        return std::string(""); // TODO: redo this statement. Errors should works independent.
    }

    unsigned long long currentTime = static_cast<unsigned long long>(std::chrono::system_clock::now().time_since_epoch().count() / nanoseconds);
    unsigned long long elapsedTime = currentTime - timeFromFile;

    // TODO: redo to independent check function.
    if (strcmp(wordOfTheDay.data(), "NAN") == 0) {
        if (elapsedTime > secondsMinutesHours) {
            timeForDailyGame = currentTime;
            wordOfTheDay = dictionary[rand() % dictionary.size()];
            return wordOfTheDay;
        }

        return std::string("");
    }
    else {
        return wordOfTheDay;
    }
}

void saveToFile(std::string wordOfTheDay, unsigned long long time) {
    std::ofstream oFile;
    oFile.open("save.ini");

    if (oFile.is_open()) {
        oFile << wordOfTheDay << std::endl;
        oFile << time << std::endl;
    }
    oFile.close();

}

void processInitState(std::vector<std::string>& dictionary) {
    srand(time(nullptr));

    loadDictionaryFromFile(dictionary);

    if (!tryToLoadSavedGamesFromFile()) {
        timeForDailyGame = static_cast<unsigned long long>(std::chrono::system_clock::now().time_since_epoch().count() / nanoseconds);
        saveToFile(dictionary[rand() % dictionary.size()], timeForDailyGame); // generate word for daily game and save 
    }
}

int processMenuState() {
    int userInput = 0;

    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "*                        WELCOME to Wordle GAME                       *" << std::endl;
    std::cout << "*                Get 6 chances to guess a 5-letter word               *" << std::endl;
    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
    std::cout << "*                               How To Play                           *" << std::endl;
    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
    std::cout << "*   - Guess the Wordle in 6 tries.                                    *" << std::endl;
    std::cout << "*   - Each guess must be a valid 5-letter word.                       *" << std::endl;
    std::cout << "*   - Tiles will change to show how close your guess was to the word. *" << std::endl;
    std::cout << "*         Examples:                                                   *" << std::endl;
    std::cout << "*                   [\x1b[32mW\x1b[0m][E][A][R][Y]                                   *" << std::endl;
    std::cout << "*              [\x1b[32mW\x1b[0m] is in the word and in the correct spot.            *" << std::endl;
    std::cout << "*                   [P][\x1b[33mI\x1b[0m][L][L][S]                                   *" << std::endl;
    std::cout << "*              [\x1b[33mI\x1b[0m] is in the word but in the wrong spot.              *" << std::endl;
    std::cout << "*                   [V][A][G][\x1b[31mU\x1b[0m][E]                                   *" << std::endl;
    std::cout << "*              [\x1b[31mU\x1b[0m] is not in the word in any spot.                    *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
   // std::cout << "\x1b[32m green text on regular background \x1b[0m" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
    std::cout << "Enter 1 - to PLAY Wordle of the DAY.                                  *" << std::endl;
    std::cout << "Enter 2 - to PLAY RANDOM Wordle.                                      *" << std::endl;
    std::cout << "Enter 0 - to EXIT ;(                                                  *" << std::endl;
    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
    std::cin >> userInput;
    return userInput;
}

bool processPlay(std::string& wordOfTheDay) {
    int userAttempts = 0;
    int isPlay = true;
    std::string userInput;
    // char* word = wordOfTheDay.data();

    if (QA_MODE) {
        std::cout << wordOfTheDay << std::endl;
    }

    // TODO: crutch! Dive deep - Why std::getline(std::cin, userInput) in while loop doesn't work correctly without it
    std::cin.get();
    while (isPlay) {
        std::cout << "Attempt #" << userAttempts + 1 << std::endl;
        std::getline(std::cin, userInput); // todo: check user input only 5 letters, no digit and spec symbols, no spaces.

        transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        if (strcmp(userInput.data(), wordOfTheDay.data()) == 0) {
            std::cout << "Congradulation YOU WIN!!!" << std::endl;
            std::cout << "Press ANY Key to go to MENU. " << std::endl;
            std::cin.get();
            isPlay = false;
        }
        else {
            for (int i = 0; i < userInput.length(); i++) { // check each letters in rigth place
                if (wordOfTheDay[i] == userInput[i]) {
                    std::cout << "[\x1b[32m" << wordOfTheDay[i] << "\x1b[0m]";
                }
                else {
                    bool tmpFlag = false; // temporary variable = need redo this chunk of code to function
                    for (int k = 0; k < userInput.length(); k++) { // check each letters in whole word
                        if (userInput[i] == wordOfTheDay[k]) {
                            std::cout << "[\x1b[33m" << wordOfTheDay[k] << "\x1b[0m]"; // std::cout << static_cast<char>(std::tolower(wordOfTheDay[k]));
                            tmpFlag = true;
                            break;
                        }
                    }
                    if (!tmpFlag) {
                        std::cout << "[\x1b[31m" << userInput[i] << "\x1b[0m]"; // std::cout << "*";
                    }
                }
            }
            std::cout << std::endl;

            userAttempts++;
            if (userAttempts == 5) {
                std::cout << "After " << userAttempts << "attempts, YOU LOSE ;( Try next time!" << std::endl << std::endl;
                std::cout << "Press ANY Key to go to MENU. " << std::endl;
                std::cin.get();
                isPlay = false;
            }
        }
    }

    return isPlay;
}

bool processDayGameLoopState(std::vector<std::string>& dictionary) {
    std::cout << ">>  Welcome to DAILY GAME! <<" << std::endl << std::endl;

    std::string wordOfTheDay = loadFromFile(dictionary);
    if (wordOfTheDay.empty()) {
        std::cout << "YOU already PLAYED in daily word! Try in a next day!" << std::endl;
        std::cout << "Press ANY Key to go to MENU. " << std::endl << std::endl << std::endl;
        std::cin.get();
    }
    else {
        if (!processPlay(wordOfTheDay)) {
            saveToFile("NAN", timeForDailyGame);
        }
    }

    return false;
}

bool processRandomGameLoopState(std::vector<std::string>& dictionary) {
    std::cout << ">>  Welcome to RANDOM WORD GAME! <<" << std::endl << std::endl;
    return processPlay(dictionary[rand() % dictionary.size()]);
}

void processExitState() {
    std::cout << "EXIT" << std::endl;
}

int main() {
    GameState curGameState = GameState::INIT;
    bool isExit = false;
    std::vector<std::string> dictionary;
    dictionary.reserve(3000);

    while (!isExit) {
        switch (curGameState) {
        case GameState::INIT: {
            processInitState(dictionary);
            curGameState = GameState::MENU;
            break;
        }
        case GameState::MENU: {
            int userInput = processMenuState();

            if (userInput == 1) {
                curGameState = GameState::DAILY_GAME_MODE;
            }
            else if (userInput == 2) {
                curGameState = GameState::RANDOM_GAME_MODE;
            }
            else if (userInput == 0) {
                curGameState = GameState::EXIT;
            }
            else {
                std::cout << "This menu item is NOT exist! Try again." << std::endl;
            }
            break;
        }
        case GameState::DAILY_GAME_MODE: {
            if (!processDayGameLoopState(dictionary)) {
                curGameState = GameState::MENU;
            }
            break;
        }
        case GameState::RANDOM_GAME_MODE: {
            if (!processRandomGameLoopState(dictionary)) {
                curGameState = GameState::MENU;
            }
            break;
        }
        case GameState::EXIT: {
            processExitState();
            isExit = true;
            break;
        }
        default: {
            std::cout << "Something went wrong please text to developer!" << std::endl;
            break;
        }
        }
    }

    return 0;
}
