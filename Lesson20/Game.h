#pragma once
#include "Munchkin.h"
#include "DeckHelper.h"
//#include "ItemDeck.h"
//#include "MonsterDeck.h"
//#include "ModifierDeck.h"

class Game
{
public:
    Game() = default;
    void run();

private:
    void generateMunchkinInitialCards();
    Monster* generateMonster();

private:
    Munchkin m_munchkin;
    DeckHelper m_Decks;
//    ItemDeck m_itemsDeck;
//    ModifierDeck m_modifiersDeck;
//    MonsterDeck m_monstersDeck;
};
