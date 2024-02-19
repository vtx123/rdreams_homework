#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
    m_modifiersDatabase =
    {
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{4},
        new SimpleModifier{4},
        new SimpleModifier{4},
        new DoubleMunchkinLevel{},
        new DoubleMunchkinLevel{},
        new DoubleMunchkinLevel{},
        new HalvesMonsterLevel{Tribe::Animal},
        new HalvesMonsterLevel{Tribe::Animal},
        new HalvesMonsterLevel{Tribe::Animal},
        new HalvesMonsterLevel{Tribe::Human},
        new HalvesMonsterLevel{Tribe::Human},
        new HalvesMonsterLevel{Tribe::Human},
        new HalvesMonsterLevel{Tribe::Plant},
        new HalvesMonsterLevel{Tribe::Plant},
        new HalvesMonsterLevel{Tribe::Plant},
        new HalvesMonsterLevel{Tribe::Robot},
        new HalvesMonsterLevel{Tribe::Robot},
        new HalvesMonsterLevel{Tribe::Robot},
        new HalvesMonsterLevel{Tribe::Zombie},
        new HalvesMonsterLevel{Tribe::Zombie},
        new HalvesMonsterLevel{Tribe::Zombie},
        new HalvesMonsterLevel{Tribe::Undead},
        new HalvesMonsterLevel{Tribe::Undead},
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
