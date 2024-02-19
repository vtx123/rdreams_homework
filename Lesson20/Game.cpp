#include "Game.h"

#include <iostream>
#include <chrono> //for sleep delays
#include <thread> //for sleep delays
#include <time.h> //for rand generator init
#include <conio.h>

#include "Fight.h"
#include "Item.h"
#include "Modifier.h"
#include "Monster.h"

enum class GameState {
    GAME_INIT = 0,
    GAME_MENU,
    GAME_PLAY,
    GAME_FIGHT,
    GAME_RESTART,
    GAME_QUIT
};

namespace UI
{
    void printDelayWithText(int count, const std::string& text)
    {
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
        std::cout << "+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +" << std::endl;
        std::cout << "|                          CONGRATS: MunchkinG WON!                          |" << std::endl;
        std::cout << "+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +" << std::endl << std::endl;
    }

    void pressAnyKeyToContinue()
    {
        //Can use platform specific system functions to 
        //receive input directly from the keyboard without 
        //its output to console and approval with Enter

        std::cout << "Press any key to start a round..." << std::endl;
        _getch();
    }

    void printMunchkinLost(Monster* monster)
    {
        std::cout << "+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +" << std::endl;
        std::cout << "           YOU'VE LOST to \"" << monster->getName() << "\" Monster!" << std::endl;
        std::cout << "      You lose:  " << monster->getRunawayPolicy()->getFullInfo() << std::endl;
        std::cout << "+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +" << std::endl << std::endl;
        //#TODO: Print runaway policy monster dealt to Munchkin
    }

    void printIntro(Munchkin* munchkin)
    {
        // Ледяная как смерть капля падает вам за шиворот
        // Теплый след от телепорта и легкий туман сырых стен подземелья не помогают вам вспомнить ваше имя.
        // А может быть три последние бокала были лишние?...
        // НННеважно, Отныне вас зовут:
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "|                   WELCOME TO TEXT-BASED MANCKIN GAME!!!                    |" << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "|        Bone-chilling droplet falls by your nape!                           |" << std::endl;
        std::cout << "| The warm teleportation imprint and mild haze of the wet dungeon            |" << std::endl;
        std::cout << "| don't help you remember your name.                                         |" << std::endl;
        std::cout << "|                                Or maybe... last three wine were extra?..   |" << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl << std::endl;
        
        std::cout << "a-a-Anyway, now YOUR NAME is: ";
        
        std::string name;
        std::cin >> name;
        munchkin->setName(name);

        std::cout << std::endl << "                              -  -  -  -  -  -  -                              ";
        std::cout << std::endl << std::endl;

        UI::printTossing();
    }

    void printItems(Munchkin* munchkin, bool forRemove = false)
    {
        const std::vector<Item*>& items = munchkin->getItems();
        std::cout << "| Your OUTFIT:                                                               |"<< std::endl;
        if (forRemove) {
            int idx = 1;
            std::cout << "   [ 0. ] = NOTHING!" << std::endl;
            for (Item* item : items)
            {
                    std::cout << "   [ " << idx++ << ". ] = " << item->getFullInfo();
            }
        }
        else {
            for (Item* item : items)
            {
                    std::cout << "         > " << item->getFullInfo();
            }
        }
    }

    void printModifiers(Munchkin* munchkin)
    {
        const std::vector<Modifier*> modifiers = munchkin->getModifiers();
        std::cout << "| Hand CARDS:                                                                |"<< std::endl;
        int idx = 1;
        for (Modifier* modifier : munchkin->getModifiers())
        {
            std::cout << "   [ "<< idx++ << ". ] = " << modifier->getFullInfo() << std::endl;
        }
    }

    enum class UserInput
    {
        None,
        Runaway,
        ApplyModifier,
        Continue,
        Waiting,
        Quit
    };

static bool smallUI = false;
    UserInput printPlayerDeck(Munchkin* munchkin)
    {
        // Что ты будешь делать дальше?
        // 1. Я пришел в этот мир чтобы ОТКРЫВАТЬ ДВЕРИ и НАДИРАТЬ ЖЕПЫ, как видешь двери я уже открыл.
        // 2. Седеть в углу и реветь как белуга.
        // 3. Покинуть данж красиво.
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "|                            WHAT will YOU do NEXT?                          |" << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "  Munchkin " << "\"" << munchkin->getName() << "\", level " << munchkin->getLevel() << std::endl;
        printItems(munchkin);
        printModifiers(munchkin);
        if(!smallUI) {
            std::cout << "+----------------------------------------------------------------------------+" << std::endl;
            std::cout << "| 1. I came in this world for OPEN a DOORS and KICK an ASSES ...             |" << std::endl;
            std::cout << "|    as you see, door i've already opened.                                   |" << std::endl;
            std::cout << "| 2. DROP OUTFIT and CRYING in the corner like beluga...                     |" << std::endl;
            std::cout << "| 3. LEAVE the DUNGEON with sparkling flashes.                               |" << std::endl;
            std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        }else {
            std::cout << "+----------------------------------------------------------------------------+" << std::endl;
            std::cout << "| 1. Next FIGHT        2. DROP item from OUTFIT       3. LEAVE the DUNGEON   |" << std::endl;
            std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        }
        std::cout << ">> ";
        int ch = 1;
        std::cin >> ch;
        
        if(ch == 1){
            return UserInput::Continue;
        } else if(ch == 2) {
            return UserInput::Waiting;
        } else if(ch == 3){
            return UserInput::Quit;
        } else {
            return UserInput::Waiting;
        }
    }

    void printMunchkinPower(Munchkin* munchkin, Fight* fight)
    {
        std::cout << "          <---]- \"" << munchkin->getName() << "\" power: " << fight->getMunchkinPower() << ", level: " << munchkin->getLevel() << " -\n";
        std::cout << "   V.S." << std::endl;
    }

    void printMonsterPower(Monster* monster, Fight* fight)
    {
        std::cout << "          <---]- \"" << monster->getName() << "\" power: " << fight->getMonsterPower() << " -\n";
    }

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

        if (choice > handSize || choice <= 0)
        {
            choice = -1;
        }

        return choice;
    }

    void tooMuchItemsInOutfit() {
        std::cout << "   --- Wo-Wo-Wo... You are ower itemed... DROP something from OUTFIT ---" << std::endl << std::endl;
    }

    int dropItemFromOutfit(unsigned short outfitSize)
    {
        std::cout << "What you want to DROP?: ";
        int choice = -1;
        std::cin >> choice;

        if (choice > outfitSize || choice <= 0)
        {
            choice = -1;
        }

        return choice;
    }

    void printCurrentFightResult(int powerDifference)
    {
        std::cout << "                                        You are missing " << std::abs(powerDifference) << " power!\n\n";
    }

    void printMonsterInfo(Monster* monster)
    {
        std::cout << "\n--- Monster \"" << monster->getName() << "\"" << ", of " << getTribeString(monster->getTribe()) 
                  << ", level " << monster->getLevel() << ". " << std::endl;
        std::cout << "                             Run away: " << monster->getRunawayPolicy()->getFullInfo() << std::endl;

        if(monster->getBonusPolicy() != nullptr){
            std::cout << "                             Bonus away: " << monster->getBonusPolicy()->getFullInfo() << std::endl;
        }
        std::cout << std::endl;
        //#TODO: Print RUNAWAY POLICIES info similar to items print in printPlayerDeck()
    }

    void printUserFastQuit(Munchkin* munchkin){
        std::cout << std::endl << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "| ULTRA brightest sparks burn out your eyes, highlighting gamelife mistakes. |" << std::endl;
        std::cout << "| Your body will superb dung for local flora.                                |" << std::endl;
        std::cout << "|                                                  But who will care...      |" << std::endl;
        std::cout << "|                                                                            |" << std::endl;
        std::cout << "   Good Luck Machkin " << munchkin->getName() << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl << std::endl;
        std::cout << "                              -  -  -  -  -  -  -                             ";
    }
    
    void awesomeWinner(Munchkin* munchkin) {
        std::cout << std::endl << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl;
        std::cout << "|   (\\___/)              YOU are AbsolutlY IncrediblE              (\\___/)   |" << std::endl;
        std::cout << "|   (='.'=)     *   *                awesome             *   *     (='.'=)   |" << std::endl;
        std::cout << "|   ((\")_(\")                   !!!   WINNNER   !!!                (\")_(\"))   |" << std::endl;
        std::cout << "+----------------------------------------------------------------------------+" << std::endl << std::endl;
    }
} //namespace UI

void Game::run()
{
    //Can be moved to config file for pre-setup of the game
    constexpr uint WinningLevel = 10;
    GameState curState = GameState::GAME_INIT;
    
    while (curState != GameState::GAME_QUIT) {
        switch (curState) {
            case GameState::GAME_INIT:
            {
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
                if(m_munchkin.getLevel() < WinningLevel) {
                    const UI::UserInput input = UI::printPlayerDeck(&m_munchkin);
                    UI::smallUI = true;
                    
                    if(input == UI::UserInput::Continue){
                        UI::printMonsterSelection();
                        curState = GameState::GAME_FIGHT;
                    } else if(input == UI::UserInput::Waiting){
                        // TODO: spawn random positive or negative modifire
                        UI::printItems(&m_munchkin, true);
                        const int choice = UI::dropItemFromOutfit(static_cast<short>(m_munchkin.getItems().size()));

                        if (choice != -1) {
                            m_munchkin.removeItemByIndex(choice - 1);
                        }
                        UI::pressAnyKeyToContinue();
                        curState = GameState::GAME_PLAY;
                    } else if (input == UI::UserInput::Quit){
                        UI::printUserFastQuit(&m_munchkin);
                        
                        curState = GameState::GAME_QUIT;
                    }
                } else {
                    UI::awesomeWinner(&m_munchkin);
                    curState = GameState::GAME_QUIT;
                }
                break;
            }
            case GameState::GAME_FIGHT:
            {
                if (m_munchkin.getItems().size() > maxItemsInOutfit) {
                    UI::tooMuchItemsInOutfit();
                    curState = GameState::GAME_PLAY;
                    break;
                }
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
                        fight.victoryFlow(m_Decks);
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

                            if (choice != -1) {
                                fight.applyModifier(choice - 1);
                            }
                        }
                    }
                }
                curState = GameState::GAME_PLAY;
                break;
            }
            case GameState::GAME_RESTART: // TODO: state for future
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
    m_munchkin.setItems(m_Decks.generateItems());
    m_munchkin.addModifiers(m_Decks.generateModifiers());
}

Monster* Game::generateMonster()
{
    return  m_Decks.generateMonster();;
}
