#pragma once
#include "Munchkin.h"
#include "DeckHelper.h"

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
    static const int maxItemsInOutfit = 3;
};
