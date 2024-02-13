#pragma once
#include <string>

enum class Tribe
{
    Human,
    Animal,
    Plant,
    Undead,
    Zombie,
    Robot,
    God,
    Count	//call static_cast<int>(Tribe::Count) to get the number of entries in enum
};

constexpr const std::string getTribeString(Tribe tribe)
{
    switch (tribe)
    {
    case Tribe::Human: return "HUMAN";
    case Tribe::Undead: return "UNDEAD";
    case Tribe::Zombie: return "ZOMBIE";
    case Tribe::God: return "GOD";
    case Tribe::Count:
    default:
        return "";
    }
}
