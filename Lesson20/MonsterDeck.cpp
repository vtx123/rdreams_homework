#include "MonsterDeck.h"
#include <iostream>
#include <algorithm>

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
    m_monstersDatabase =
    {
        //#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
        new Monster{"Stuffy Slime", 1, Tribe::Undead, new Runaway_ItemEquipedRemoval(),new Bonus_AddItem()},
        new Monster{"Drone without AI", 1, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Self-confident Skeleton", 1, Tribe::Undead, new Runaway_LevelDowngrade{1},new Bonus_AddItem()},
        new Monster{"OneLegged RoboDog", 2, Tribe::Robot, new Runaway_ItemEquipedRemoval()},
        new Monster{"TV Zombied Rabbit", 2, Tribe::Zombie, new Runaway_LevelDowngrade{1},new Bonus_AddItem()},
        new Monster{"AssHolished Zombie", 2, Tribe::Zombie, new Runaway_ModifierFromHandRemoval()},
        new Monster{"Alarm Clock", 3, Tribe::Robot, new Runaway_LevelDowngrade{1},new Bonus_AddItem()},
        new Monster{"Vampire Vegan", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"Little Foot", 4, Tribe::Animal, new Runaway_LevelDowngrade{1}, new Bonus_AddModifier()},
        new Monster{"Ghost Of Sashimi", 4, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"Crazy Joel", 5, Tribe::Human, new Runaway_LevelDowngrade{1},new Bonus_AddModifier()},
        new Monster{"Heisen Bug", 5, Tribe::Human, new Runaway_LevelDowngrade{1}},
        new Monster{"Daddy Bear Burger", 6, Tribe::Animal, new Runaway_LevelDowngrade{1},new Bonus_AddModifier()},
        new Monster{"Global Null Pointer", 7, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Zombie Paladinium", 8, Tribe::Zombie, new Runaway_ItemEquipedRemoval(),new Bonus_AddModifier()},
        new Monster{"FatBoys Ogres", 9, Tribe::Animal, new Runaway_ModifierFromHandRemoval()},
        new Monster{"A Mimic of MemeFrog", 10, Tribe::Animal, new Runaway_ItemEquipedRemoval(),new Bonus_AddModifier()},
        new Monster{"Intern QA", 10, Tribe::Human, new Runaway_ModifierFromHandRemoval()},
        new Monster{"Gypsy Grape", 11, Tribe::Plant, new Runaway_LevelDowngrade{1},new Bonus_AddItem()},
        new Monster{".Net7 Troll", 12, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"Redneck Tree", 13, Tribe::Plant, new Runaway_ModifierFromHandRemoval(),new Bonus_AddItem()},
        new Monster{"Dryad with Surprise", 14, Tribe::Plant, new Runaway_LevelDowngrade{1}},
        new Monster{"Chernobyl Marigold", 15, Tribe::Plant, new Runaway_ItemEquipedRemoval(),new Bonus_AddModifier()},
        new Monster{"Ghost in the Shelves", 16, Tribe::Undead, new Runaway_ModifierFromHandRemoval()},
        new Monster{"The Evil Eye", 17, Tribe::Zombie, new Runaway_LevelDowngrade{1},new Bonus_AddModifier()},
        new Monster{"Dev Gaslighter", 18, Tribe::Human, new Runaway_ItemEquipedRemoval()},
        new Monster{"Shaitan Machine", 19, Tribe::Robot, new Runaway_ModifierFromHandRemoval(),new Bonus_AddModifier()},
        new Monster{"Shiba ~Destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},

    };
}

MonsterDeck::~MonsterDeck()
{
    //TODO: Clear memory
    for ( int i = 0; i < m_monstersDatabase.size(); i++)
    {
        delete m_monstersDatabase[i];
    }
}

Monster* MonsterDeck::getMonster() {
    auto val = m_monstersDatabase.back();
    m_monstersDatabase.pop_back();
    return val;
}
//Monster* MonsterDeck::generateMonster() const
//{
    //#TODO: this call should return new monster every time
    //either for as long as the same game is being played
    //or unless ALL cards were generated from database to the game - in this case 
    //make ALL cards available again

//    const int choice = std::rand() % m_monstersDatabase.size();
//    return m_monstersDatabase[choice];
    
//    const int n = m_monstersDatabase.size();
//    for (int i=0; i<n ;i++)
//    {
//        // Random for remaining positions.
//        int r = i + (rand() % (n - i));
// 
//        std::swap(m_monstersDatabase[i], m_monstersDatabase[r]);
//    }
//    return m_monstersDatabase[1];
//}
