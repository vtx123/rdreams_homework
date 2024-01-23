#pragma once

enum class Tribe
{
    Human,
    Undead,
    Zombie,
    God,
    Count	//call static_cast<int>(Tribe::Count) to get the number of entries in enum
};