#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
    m_modifiersDatabase =
    {
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{4},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new DoubleMunchkinLevel{},
        new DoubleMunchkinLevel{},
        new HalvesMonsterLevel{Tribe::Undead},
        new HalvesMonsterLevel{Tribe::God}
    };
}

ModifierDeck::~ModifierDeck()
{
    //TODO: Clear memory
    for ( int i = 0; i < m_modifiersDatabase.size(); i++)
    {
        delete m_modifiersDatabase[i];
    }
}

//#TODO: This code is similar to the one used in MonsterDeck
//Combine it under one hierarchy using inheritance
//Or move duplicated code into its own Helper Class and use composition of it
//In ModifierDeck and MonsterDeck
Modifier* ModifierDeck::geteModifier()
{
    //#TODO: this call should return new monster every time
    //either for as long as the same game is being played
    //or unless ALL cards were generated from database to the game - in this case 
    //make ALL cards available again

//    unsigned int idx = std::rand() % m_modifiersDatabase.size();
//    return m_modifiersDatabase[idx];
    auto val = m_modifiersDatabase.back();
    m_modifiersDatabase.pop_back();
    return val;
}
