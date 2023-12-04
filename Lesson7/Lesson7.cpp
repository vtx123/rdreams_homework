// The Gratest Alchemist Game
// 
// I tryed to avoid to using functions
// there is no sorting in highscore.ini

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    enum class GameState {
        INIT = 1,
        MAIN_MENU,
        GAME,
        SCORE_TABLE,
        EXIT
    };

    enum class CharacterName {
        WOMAN = 1,
        MAN,
        LADY,
        GENTLEMAN,
        PALADIN,
        ASSASIN,
        GIRL,
        BOY,
        ELF,
        LORD,
        DRAGON
    };

    enum class CharacterAge {
        TINY = 1,
        TALL,
        GORGEOUS,
        CHARMING,
        CUTE,
        SEXY,
        UGLY,
        NOT_S_CLAVER,
        OLD,
        YOUNG,
        SMELLY
    };

    std::vector<std::string> scoreTableName = {};
    std::vector<int> scoreTableScore = {};

    GameState curGameState = GameState::INIT;
    std::srand(std::time(nullptr));

    const int GeneratingRange = 50;
    const int GeneratingCharRange = 10;
    double generatedNum = -1;
    double generatedCharacter = -1;

    std::string userName = "";
    int userNumber = 0;
    int userAttempts = 0;
    int userBestResult = 999;
    int userPositionInScoreTable = 0;
    int menuControl = 0;
    bool isStrangeClient = false;
    bool quit = false;

    while (!quit) {
        switch (static_cast<GameState>(curGameState)) {
        case GameState::INIT: { // init process
            curGameState = GameState::MAIN_MENU;

            break;
        }
        case GameState::MAIN_MENU: { // main menu content
            system("cls"); // system("clear");

            std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
            std::cout << "*                WELCOME! to the GRATE ALCHEMIST CLUB!                    *" << std::endl;
            std::cout << "*         Dear, POTION MASTER. You were invited to our club!              *" << std::endl;
            std::cout << "*          You will able to work in one of our potion SHOP                *" << std::endl;
            std::cout << "*          and help people prepare potions by thir recipts.               *" << std::endl;
            std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
            std::cout << "*                                                                         *" << std::endl;
            std::cout << "* put '1' to APPLY or                                                     *" << std::endl;
            std::cout << "* put '2' to DECLINE an offer                                             *" << std::endl;
            std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
            std::cin >> menuControl;

            if (menuControl == 1) {
                system("cls"); // system("clear");

                std::cout << "What's your name?" << std::endl;
                std::cin >> userName;
                if (userName.size() >= 10) {
                    userName.erase(9);
                }
                std::cout << "Ok, " << userName << ". As a Knight Bachelor of GRATE ALCHEMIST CLUB!" << std::endl;
                std::cout << "I'm glad to present to you one of THE BEST potion SHOP." << std::endl;
                std::cout << "We will teleport you immidiately to there. Please sit down in this cosy armchair..." << std::endl;

                system("pause"); // system("read"); // Press any key to Continue
                curGameState = GameState::GAME;
            }
            else if (menuControl == 2) {
                curGameState = GameState::EXIT;
                std::cout << "You decided to NOT TAKING PART in competition." << std::endl;
                std::cout << "\"You will NEVER LOSE if you NEVER PLAY.\"" << std::endl;
                std::cout << "             Smart decision... GOOD LUCK!" << std::endl;
            }

            break;
        }
        case GameState::GAME: { // game process
            system("cls"); // system("clear");

            std::cout << "You waking up in a cozy armchair near your alchemist table." << std::endl;
            std::cout << "Myriads of magical potions shine on the shelves around you..." << std::endl;
            std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;

            // create a character
            generatedCharacter = (std::rand() % GeneratingCharRange) + 1; // generate random number from 1 to 11
            switch (static_cast<CharacterAge>(generatedCharacter)) {
            case CharacterAge::TINY:
                std::cout << "a TINY ";
                break;
            case CharacterAge::TALL:
                std::cout << "a TALL ";
                break;
            case CharacterAge::GORGEOUS:
                std::cout << "a GORGEOUS ";
                break;
            case CharacterAge::CHARMING:
                std::cout << "a CHARMING ";
                break;
            case CharacterAge::CUTE:
                std::cout << "a CUTE ";
                break;
            case CharacterAge::SEXY:
                std::cout << "a SEXY ";
                break;
            case CharacterAge::UGLY:
                std::cout << "an UGLY ";
                break;
            case CharacterAge::NOT_S_CLAVER:
                std::cout << "a NOT SUPER CLAVER ";
                break;
            case CharacterAge::OLD:
                std::cout << "an OLD ";
                break;
            case CharacterAge::YOUNG:
                std::cout << "a YOUNG ";
                break;
            case CharacterAge::SMELLY:
                std::cout << "a SMELLY ";
                break;
            default:
                std::cout << "a YOUNG ";
                break;
            }

            isStrangeClient = rand() % 2; // additional random for customers 0 or 1
            if (isStrangeClient) {
                std::cout << "weird one ";
            }

            generatedCharacter = (std::rand() % GeneratingCharRange) + 1; // generate random number from 1 to 11
            switch (static_cast<CharacterName>(generatedCharacter)) {
            case CharacterName::WOMAN:
                std::cout << "WOMAN ";
                break;
            case CharacterName::MAN:
                std::cout << "MAN ";
                break;
            case CharacterName::LADY:
                std::cout << "LADY ";
                break;
            case CharacterName::GENTLEMAN:
                std::cout << "GENTLEMAN ";
                break;
            case CharacterName::PALADIN:
                std::cout << "PALADIN ";
                break;
            case CharacterName::ASSASIN:
                std::cout << "ASSASIN ";
                break;
            case CharacterName::GIRL:
                std::cout << "GIRL ";
                break;
            case CharacterName::BOY:
                std::cout << "BOY ";
                break;
            case CharacterName::ELF:
                std::cout << "ELF ";
                break;
            case CharacterName::LORD:
                std::cout << "LORD ";
                break;
            case CharacterName::DRAGON:
                std::cout << "DRAGON ";
                break;
            default:
                std::cout << "GIRL ";
                break;
            }
            std::cout << "walks into YOUR SHOP and says:" << std::endl;

            // create question 1
            generatedNum = std::rand() % (GeneratingRange + 1); // generate random number from 0 to 50

            if (!isStrangeClient) {
                if (generatedNum == 0) { // for SOFT MODE
                    std::cout << " - \"A-a... Oyh... M-m-m... br-r-r!\"" << std::endl; // 0
                }
                else if (generatedNum >= 1 && generatedNum <= 10) {
                    std::cout << " - \"Give me VERY FEW potions.\"" << std::endl; // 1-10
                }
                else if (generatedNum >= 11 && generatedNum <= 20) {
                    std::cout << " - \"Give me FEW potions.\"" << std::endl; // 11-20
                }
                else if (generatedNum >= 21 && generatedNum <= 30) {
                    std::cout << " - \"Give me an AVERAGE amount of potions.\"" << std::endl; // 21-30
                }
                else if (generatedNum >= 31 && generatedNum <= 40) {
                    std::cout << " - \"Give me A LOT of potions.\"" << std::endl; // 31-40
                }
                else if (generatedNum >= 41 && generatedNum <= 50) {
                    std::cout << " - \"Give me HEAPS of potions.\"" << std::endl; // 41-50
                }
            }
            else { // for HARD MODE
                std::cout << " - \"Give me SOME potions.\"" << std::endl; // 1-50
            }

            std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;

            while (true) {
                std::cout << "HOW MANY potions will you GIVE?" << std::endl; // 1-50
                std::cin >> userNumber;
                userAttempts++;

                if (userNumber < 0) // EXIT
                {
                    std::cout << "Screaming Ah-Ah-Ah-a-a, you jump out the window..." << std::endl;
                    std::cout << "The Academy of Alchemists and the best adventurers " << std::endl;
                    std::cout << "will search though the forests in vain for you... A ve-e-e-ery long time..." << std::endl;
                    std::cout << std::endl;
                    std::cout << "Be careful there are a lot of wandering bear. GOOD LUCK!" << std::endl;
                    std::cout << std::endl;
                    // std::cout << "[Enter to Quit]" << std::endl;
                    system("pause"); // system("read"); // Press any key to Continue

                    curGameState = GameState::EXIT;
                    break;
                }

                if (userNumber > 50) {
                    std::cout << "WoW-WoW!!! You were CONFUSED, but a thought flashed through your mind - " << std::endl;
                    std::cout << "I MUST put a NUMBER from 0 to 50. Will be Tryed AGAIN." << std::endl;
                    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
                    continue;
                }

                // create question 2
                if (userNumber > generatedNum) {
                    if ((userNumber - generatedNum) >= 20) {
                        std::cout << " - \"I need MUCH LESS\"" << std::endl;
                    }
                    if ((userNumber - generatedNum) >= 10) {
                        std::cout << " - \"I need LESS\"" << std::endl;
                    }
                    else {
                        std::cout << " - \"I need A BIT LESS\"" << std::endl;
                    }
                }
                else if (userNumber < generatedNum) {
                    if ((generatedNum - userNumber) >= 20) {
                        std::cout << " - \"I need MUCH MORE\"" << std::endl;
                    }
                    if ((generatedNum - userNumber) >= 10) {
                        std::cout << " - \"I need MORE\"" << std::endl;
                    }
                    else {
                        std::cout << " - \"I need A BIT MORE\"" << std::endl;
                    }
                }
                else {
                    // Player WIN
                    if (userAttempts < userBestResult) {
                        userBestResult = userAttempts;
                    }
                    std::cout << " - \"WONDERFUL! You are AWESOME!!!\"" << std::endl;
                    std::cout << "a satisfied customer closes the door behind..." << std::endl;
                    std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl;
                    std::cout << "You feel as your RAITING is GROWING..." << std::endl;
                    std::cout << "You spend " << userAttempts << " times to find right amout of potions." << std::endl;
                    std::cout << "Remembering your best result " << userBestResult << " you are following in sleep..." << std::endl;
                    // std::cout << "[Enter to WAKE UP]" << std::endl;

                    system("pause"); // system("read"); // Press any key to Continue

                    userAttempts = 0;
                    curGameState = GameState::SCORE_TABLE;
                    break;
                }
            }

            break;
        }
        case GameState::SCORE_TABLE: { // SCORE_TABLE content
            system("cls"); // system("clear");

            std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
            std::cout << "*               RAITING of THE Royal Alchemists Academy.                  *" << std::endl;
            std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
            std::cout << "* [Press ANY KEY to WAKE UP]                                              *" << std::endl;
            std::cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << std::endl << std::endl << std::endl;

            if (userPositionInScoreTable == 0) { // parce file first time and add new user to a table // sorting TBD in a future
                std::ifstream iFile("highscore.ini");
                if (iFile.is_open()) { // Read the file highscore.ini
                    int score = 0;

                    std::string line;
                    int i = 0;
                    std::string::size_type pos = 0;

                    while (getline(iFile, line, '|')) {
                        pos = line.find('\n');
                        if (pos != std::string::npos) {
                            line.erase(pos, 1);
                        }

                        if (line == "") {
                            break;
                        }

                        if (i % 2 == 0) {
                            scoreTableName.push_back(line);
                        }
                        else {
                            scoreTableScore.push_back(stoi(line));
                        }

                        i++;
                    }
                    iFile.close();
                }
                else { // Create file highscore.ini and write defolt date into file
                    scoreTableName = { "King", "Lord", "Wizard", "Mage", "NoName" };
                    scoreTableScore = { 1, 3, 4, 16, 999 };

                    std::ofstream oFile;
                    oFile.open("highscore.ini");
                    if (oFile.is_open()) {

                        int i = 0;
                        while (i < scoreTableScore.size()) {
                            oFile << scoreTableName[i] << '|' << scoreTableScore[i] << "|" << std::endl;
                            i++;
                        }
                    }
                    oFile.close();
                }

                userPositionInScoreTable = scoreTableName.size();
                scoreTableName.push_back(userName);
                scoreTableScore.push_back(userBestResult);

                // Append user data into file
                std::ofstream oFile;
                oFile.open("highscore.ini", std::ios_base::app);
                if (oFile.is_open()) {
                    oFile << userName << '|' << userBestResult << "|" << std::endl;
                }
                oFile.close();
            }
            else { // update user in a table // add a flag if userBestResult not changed - no need update file.
                scoreTableName[userPositionInScoreTable] = userName;
                scoreTableScore[userPositionInScoreTable] = userBestResult;

                // copy past ;( rewrite all file
                std::ofstream oFile;
                oFile.open("highscore.ini", std::ios::trunc);
                if (oFile.is_open()) {

                    int i = 0;
                    while (i < scoreTableScore.size()) {
                        oFile << scoreTableName[i] << '|' << scoreTableScore[i] << "|" << std::endl;
                        i++;
                    }
                }
                oFile.close();
            }

            std::cout << "+-----------+----------+" << std::endl;
            std::cout << "|    Name   |   Score  |" << std::endl;
            std::cout << "+-----------+----------+" << std::endl;
            int curScore = 0;
            for (int i = 0; i < scoreTableName.size(); i++) {
                std::cout << "| " << std::setw(10) << std::setfill(' ') << std::left << scoreTableName[i] << "|";
                curScore = scoreTableScore[i];
                if (curScore >= 0 && curScore < 10) {
                    std::cout << std::setw(5) << std::setfill(' ') << std::left << " " << curScore << "    |" << std::endl;
                }
                else if (curScore >= 10 && curScore < 100) {
                    std::cout << std::setw(4) << std::setfill(' ') << std::left << " " << curScore << "    |" << std::endl;
                }
                else {
                    std::cout << std::setw(4) << std::setfill(' ') << std::left << " " << curScore << "   |" << std::endl;
                }

                std::cout << "+-----------+----------+" << std::endl;
            }

            system("pause"); // system("read"); // Press any key to Continue

            curGameState = GameState::GAME;

            break;
        }
        case GameState::EXIT: { // exit process
            quit = true;

            break;
        }
        default: {
            std::cout << "ERROR: Something went wrong. Please dotify dev department!" << std::endl;

            break;
        }
        }
    }

    return 0;
}