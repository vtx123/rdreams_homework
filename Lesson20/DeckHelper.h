#pragma once
#include <string>
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
        return m_monstersDeck.getMonster();
    }
    std::vector<Item*> generateItems(){
        return {m_itemsDeck.getItem(), m_itemsDeck.getItem()};
    }
    std::vector<Modifier*> generateModifiers(){
        return {m_modifiersDeck.geteModifier(),
            m_modifiersDeck.geteModifier(),
            m_modifiersDeck.geteModifier(),
            m_modifiersDeck.geteModifier(),
            m_modifiersDeck.geteModifier()};
    }
    Item* randomItemFromDeck(){
        return m_itemsDeck.getItem();
    }
    Modifier* randomModifierFromDeck(){
        return m_modifiersDeck.geteModifier();
    }
private:
    ItemDeck m_itemsDeck;
    ModifierDeck m_modifiersDeck;
    MonsterDeck m_monstersDeck;
};
