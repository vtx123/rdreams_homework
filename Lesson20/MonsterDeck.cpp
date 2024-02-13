#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
    m_monstersDatabase =
    {
        //#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
        new Monster{"Stuffy Slime", 1, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"Drone without AI", 1, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Self-confident Skeleton", 1, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"OneLegged RoboDog", 2, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"TV Zombied Rabbit", 2, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
        new Monster{"AssHolished Zombie", 2, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
        new Monster{"Alarm Clock", 3, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Vampire Vegan", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"Little Foot", 4, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"Ghost Of Sashimi", 4, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"Crazy Joe", 5, Tribe::Human, new Runaway_LevelDowngrade{1}},
        new Monster{"Heisen Bug", 5, Tribe::Human, new Runaway_LevelDowngrade{1}},
        new Monster{"Daddy Bear", 6, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"Global Null Pointer", 7, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Zombie Paladinium", 8, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
        new Monster{"Fat Ogre", 9, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"A Mimic", 10, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"Intern QA", 10, Tribe::Human, new Runaway_LevelDowngrade{1}},
        new Monster{"Gypsy Grape", 11, Tribe::Plant, new Runaway_LevelDowngrade{1}},
        new Monster{".Net7 Troll", 12, Tribe::Animal, new Runaway_LevelDowngrade{1}},
        new Monster{"Redneck Tree", 13, Tribe::Plant, new Runaway_LevelDowngrade{1}},
        new Monster{"Dryad with Surprise", 14, Tribe::Plant, new Runaway_LevelDowngrade{1}},
        new Monster{"Chernobyl Marigold", 15, Tribe::Plant, new Runaway_LevelDowngrade{1}},
        new Monster{"Ghost in the Shelves", 16, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"The Evil Eye", 17, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
        new Monster{"Dev Gaslighter", 18, Tribe::Human, new Runaway_LevelDowngrade{1}},
        new Monster{"Shaitan Machine", 19, Tribe::Robot, new Runaway_LevelDowngrade{1}},
        new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},

    };
}

MonsterDeck::~MonsterDeck()
{
    //TODO: Clear memory
}

Monster* MonsterDeck::generateMonster() const
{
    //#TODO: this call should return new monster every time
    //either for as long as the same game is being played
    //or unless ALL cards were generated from database to the game - in this case 
    //make ALL cards available again

    const int choice = std::rand() % m_monstersDatabase.size();
    return m_monstersDatabase[choice];
}
