#pragma once
#include <string>
#include "Tribe.h"
#include "Runaway.h"
#include "Bonus.h"

class Runaway;

class Monster
{
public:
    Monster(const std::string& name, int level = 1, Tribe tribe = Tribe::Human, Runaway* policy = nullptr, Bonus* bonus = nullptr)
        : m_name(name), m_level(level), m_tribe(tribe), m_RunawayPolicy(policy),m_BonusPolicy(bonus) {}

    Tribe getTribe() const { return m_tribe; }
    unsigned int getLevel() const { return m_level; }
    const std::string& getName() const { return m_name; }

    Runaway* getRunawayPolicy() const { return m_RunawayPolicy; }
    Bonus* getBonusPolicy() const { return m_BonusPolicy; }

    std::string getFullInfo() const { return "Monster " + getName() + ", "
        + m_RunawayPolicy->getFullInfo() + ", " + m_BonusPolicy->getFullInfo(); }

private:
    unsigned int m_level = 1;
    Tribe m_tribe = Tribe::Human;
    std::string m_name;

    Runaway* m_RunawayPolicy = nullptr;
    //#TODO: Add bonus victory policy for losing to munchkin similar to Runaway policies
    Bonus* m_BonusPolicy = nullptr;
};
