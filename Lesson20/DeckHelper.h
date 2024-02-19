#pragma once
#include <string>
#include <iostream>
#include "ItemDeck.h"
#include "MonsterDeck.h"
#include "ModifierDeck.h"

class DeckHelper
{
public:
    DeckHelper(){
        std::srand(static_cast<int>(std::time(0)));
        shuffle(m_itemsDeck.getDB());
        shuffle(m_modifiersDeck.getDB());
        shuffle(m_monstersDeck.getDB());
    }
    ~DeckHelper(){}

    template<typename T>
    void shuffle(std::vector<T*>& deck)
    {
        const auto size = deck.size();
        for (int i=0; i < deck.size(); i++)
        {
            int r = i + (rand() % (size - i));
            std::swap(deck[i], deck[r]);
        }
    }
    Monster* generateMonster(){
        return getCardFromDeck(m_monstersDeck.getDB());
    }
    std::vector<Item*> generateItems(){
        return { getCardFromDeck(m_itemsDeck.getDB()), getCardFromDeck(m_itemsDeck.getDB()) };
    }
    std::vector<Modifier*> generateModifiers(){
        return { getCardFromDeck(m_modifiersDeck.getDB()),
            getCardFromDeck(m_modifiersDeck.getDB()),
            getCardFromDeck(m_modifiersDeck.getDB()),
            getCardFromDeck(m_modifiersDeck.getDB()),
            getCardFromDeck(m_modifiersDeck.getDB()) };
    }
    Item* randomItemFromDeck(){
        return getCardFromDeck(m_itemsDeck.getDB());
    }
    Modifier* randomModifierFromDeck(){
        return getCardFromDeck(m_modifiersDeck.getDB());
    }

    template<typename T>
    T* getCardFromDeck(std::vector<T*>& deck)
    {
        auto val = deck.back();
        deck.pop_back();
        return val;
    }

private:
    ItemDeck m_itemsDeck;
    ModifierDeck m_modifiersDeck;
    MonsterDeck m_monstersDeck;
};
