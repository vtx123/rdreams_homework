#include "Game.h"

#include <iostream>
#include <fstream>
#include <chrono> //for sleep delays
#include <thread> //for sleep delays
#include <time.h> //for rand generator init

#include "Fight.h"
#include "Item.h"
#include "ItemDeck.h"
#include "Modifier.h"
#include "Monster.h"

namespace UI
{

    void printDelayWithText(int count, const std::string& text)
    {
//        const int pause = static_cast<int>((count - 1) * 1000 / text.length());
//        for(const auto& ch:text){
//            std::this_thread::sleep_for(std::chrono::milliseconds(pause));
//            std::cout << ch;
//        }
//        std::cout << std::endl;
        std::cout << text;
        for (int i = 0; i < count; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            std::cout << ".";
        }
        std::cout << std::endl;
    }

    void printTossing()
    {
        // Пока вы ковыряете заскарузлым пальцем дырку у себя в кармане, Шайтан расстилает свои хвосты на вашем пути .....
        std::cout << "  While your shabby finger picking holes in a MAGIC POCKET," << std::endl;
        UI::printDelayWithText(5, "  Shaitan spreads out his tails in your path...");
    }

    void printMonsterSelection()
    {
        UI::printDelayWithText(5, "Selecting monster card");
    }

    void printMunchkinWon()
    {
        std::cout << "CONGRATS: MunchkinG WON!\n";
    }

    void pressAnyKeyToContinue()
    {
        //Can use platform specific system functions to 
        //receive input directly from the keyboard without 
        //its output to console and approval with Enter

        //char anyKey;
        std::cout << "Press any key to start a round...";
        //std::cin >> anyKey;
        system("read");
//        system("clear");

    }

    void printMunchkinLost(Monster* monster)
    {
        std::cout << "-------YOU'VE LOST to \"" << monster->getName() << "\"Monster!---------\n";
        //#TODO: Print runaway policy monster dealt to Munchkin
    }

//    std::string getTribeString(Tribe tribe)
//    {
//        switch (tribe)
//        {
//        case Tribe::Human: return "HUMAN";
//        case Tribe::Undead: return "UNDEAD";
//        case Tribe::Zombie: return "ZOMBIE";
//        case Tribe::God: return "GOD";
//        case Tribe::Count:
//        default:
//            return "";
//        }
//    }

    void printIntro(Munchkin* munchkin)
    {
        // Ледяная как смерть капля падает вам за шиворот
        // Теплый след от телепорта и легкий туман сырых стен подземелья не помогают вам вспомнить ваше имя.
        // А может быть три последние бокала были лишние?...
        // НННеважно, Отныне вас зовут:
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << "|           WELCOME TO TEXT-BASED MANCKIN GAME!!!            |" << std::endl;
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << "|     Bone-chilling droplet falls by your nape.              |" << std::endl;
        std::cout << "| The warm teleportation imprint and mild haze of the wet    |" << std::endl;
        std::cout << "| dungeon don't help you remember your name.                 |" << std::endl;
        std::cout << "| Or maybe... last three wine were extra?..                  |" << std::endl;
        std::cout << "+------------------------------------------------------------+"<< std::endl << std::endl;
        
        std::cout << "a-a-Anyway, now YOUR NAME is: ";
        
        std::string name;
        std::cin >> name;
        munchkin->setName(name);

        std::cout << std::endl << "                   · · · · · · · · · · · ·                    " << std::endl << std::endl;

        UI::printTossing();
    }

    void printItems(Munchkin* munchkin)
    {
        const std::vector<Item*>& items = munchkin->getItems();
        std::cout << "+        · · · · · with YOUR current OUTFIT · · · · ·        +"<< std::endl;
        for (Item* item : items)
        {
            std::cout << item->getFullInfo();
        }
    }

    void printModifiers(Munchkin* munchkin)
    {
        const std::vector<Modifier*> modifiers = munchkin->getModifiers();
        std::cout << "+           · · · · · and your HAND CARDS · · · · ·          +"<< std::endl;
        int idx = 1;
        for (Modifier* modifier : munchkin->getModifiers())
        {
            std::cout << idx++ << ". " << modifier->getFullInfo() << std::endl;
        }
    }

    void printPlayerDeck(Munchkin* munchkin)
    {
        // Что ты будешь делать дальше?
        // 1. Я пришел в этот мир чтобы ОТКРЫВАТЬ ДВЕРИ и НАДИРАТЬ ЖЕПЫ, как видешь двери я уже открыл.
        // 2. Седеть в углу и реветь как белуга.
        // 3. Покинуть данж красиво.
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << "|                  WHAT will YOU do NEXT?                    |" << std::endl;
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << "  Munchkin " << "\"" << munchkin->getName() << "\", level " << munchkin->getLevel() << std::endl;
        printItems(munchkin);
        printModifiers(munchkin);
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << "| 1. I came in this world for OPEN a DOORS and KICK an ASSES |" << std::endl;
        std::cout << "|    as you see, door i'd already opened.                    |" << std::endl;
        std::cout << "| 2. CRYING in the corner like beluga.                       |" << std::endl;
        std::cout << "| 3. LEAVE the DUNGEON with sparkling flashes.               |" << std::endl;
        std::cout << "+------------------------------------------------------------+" << std::endl;
        std::cout << ">> ";
        int ch = 1;
        std::cin >> ch;
    }

    void printMunchkinPower(Munchkin* munchkin, Fight* fight)
    {
        std::cout << "-----\"" << munchkin->getName() << "\" power: " << fight->getMunchkinPower() << "-------\n";
    }

    void printMonsterPower(Monster* monster, Fight* fight)
    {
        std::cout << "-----\"" << monster->getName() << "\" power: " << fight->getMonsterPower() << "-------\n";
    }

    enum class UserInput
    {
        None,
        Runaway,
        ApplyModifier
    };

    UserInput readUserBehavior()
    {
        std::cout << "Use card from Hand or Runaway?(M/R)";
        char choice;
        std::cin >> choice;
        choice = std::toupper(choice);

        switch (choice)
        {
        case 'R':
            return UserInput::Runaway;
        case 'M':
            return UserInput::ApplyModifier;
        default:
            return UserInput::None;
        }
    }

    int selectModifierFromHand(unsigned short handSize)
    {
        std::cout << "Select card from HAND: ";
        int choice = -1;
        std::cin >> choice;

        if (choice >= handSize || choice <= 0)
        {
            choice = -1;
        }

        return choice;
    }

    void printCurrentFightResult(int powerDifference)
    {
        std::cout << "You are missing " << std::abs(powerDifference) << " power!\n\n";
    }

    void printMonsterInfo(Monster* monster)
    {
        std::cout << "\n--------Monster \"" << monster->getName() << "\"" << ", of " <<
            getTribeString(monster->getTribe()) << ", level " << monster->getLevel() << " --------" << std::endl << std::endl;
        //#TODO: Print RUNAWAY POLICIES info similar to items print in printPlayerDeck()
    }


} //namespace UI

enum class GameState {
    GAME_INIT = 0,
    GAME_MENU,
    GAME_PLAY,
    GAME_FIGHT,
    GAME_RESTART,
    GAME_QUIT
};

void loadFromFile(const std::string& fileName) {
    std::fstream fin(fileName);
    std::string first, last;
    int id;
    float avr;
    
    while (fin >> first) {
        fin >> last >> id >> avr;
        //addStudent(Student(first, last, id, avr));
    }
}

void Game::run()
{
    //Can be moved to config file for pre-setup of the game
    constexpr uint WinningLevel = 10;
    GameState curState = GameState::GAME_INIT;
    
    while (curState != GameState::GAME_QUIT) {
        switch (curState) {
            case GameState::GAME_INIT:
            {
                std::srand(static_cast<int>(std::time(0)));
                loadFromFile("items.txt");
                //Setup Random hand for the player
                generateMunchkinInitialCards();
                
                curState = GameState::GAME_MENU;
                break;
            }
            case GameState::GAME_MENU:
            {
                UI::printIntro(&m_munchkin);
                
                curState = GameState::GAME_PLAY;
                break;
            }
            case GameState::GAME_PLAY:
            {
                while (m_munchkin.getLevel() < WinningLevel)
                {
                    UI::printPlayerDeck(&m_munchkin);

                    UI::pressAnyKeyToContinue();
                    UI::printMonsterSelection();
                }
                break;
            }
            case GameState::GAME_FIGHT:
            {
                Monster* monster = generateMonster();
                UI::printMonsterInfo(monster);
                
                Fight fight;
                fight.setMonster(monster);
                fight.setMunchkin(&m_munchkin);

                fight.start();
                
                //Fight loop
                while (!fight.getFinish())
                {
                    const int munchkinMonsterDifference = fight.getMunchkinMonsterPowerDifference();
                    UI::printMunchkinPower(&m_munchkin, &fight);
                    UI::printMonsterPower(monster, &fight);

                    if (munchkinMonsterDifference > 0)
                    {
                        fight.victoryFlow();
                        UI::printMunchkinWon();
                        UI::pressAnyKeyToContinue();
                    }
                    else
                    {
                        UI::printCurrentFightResult(munchkinMonsterDifference);
                        const UI::UserInput input = UI::readUserBehavior();

                        if (input == UI::UserInput::Runaway)
                        {
                            fight.runawayFlow();

                            UI::printMunchkinLost(monster);
                            UI::pressAnyKeyToContinue();
                        }
                        else if (input == UI::UserInput::ApplyModifier)
                        {
                            UI::printModifiers(&m_munchkin);
                            const int choice = UI::selectModifierFromHand(static_cast<short>(m_munchkin.getModifiers().size()));

                            if (choice != -1)
                                fight.applyModifier(choice - 1);
                        }
                    }
                }
                break;
            }
            case GameState::GAME_RESTART:
            {
                curState = GameState::GAME_INIT;
            }
            default:
                break;
        }
    }
    
        //State pattern may be a good candidate here
        //Every case may be its own state with transition rules, e.g.
        //Start->InProgress->Win/Runaway/ApplyModifiers, Runaway->Lost, ApplyModifiers->InProgress
        //https://refactoring.guru/uk/design-patterns/state
}

void Game::generateMunchkinInitialCards()
{
    m_munchkin.setItems(m_itemsDeck.generateItems());
    m_munchkin.addModifiers(m_modifiersDeck.generateModifiers());
}

Monster* Game::generateMonster()
{
    return m_monstersDeck.generateMonster();
}
