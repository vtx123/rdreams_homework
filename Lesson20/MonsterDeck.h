#pragma once
#include <vector>

class Monster;

class MonsterDeck
{
public:
    MonsterDeck();
    ~MonsterDeck();

    std::vector<Monster*>& getDB() { return m_monstersDatabase; }

private:
    std::vector<Monster*> m_monstersDatabase;
};
