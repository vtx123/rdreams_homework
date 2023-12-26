#pragma once
#include <iostream>
#include "Weapon.h"

enum class PlayerClass {
    DEFAULT = 1,
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Player {
public:
    Player(std::string name, int health, PlayerClass pClass);
    ~Player();

    void setWeapon(Weapon*);
    Weapon* getWeapon() const;

    std::string getName();
    void printPlayerInfo(); // name, health, class, weapon info, team info
private:
    std::string _name = "";
    int _health = 100;
    PlayerClass _pClass = PlayerClass::DEFAULT;
    Weapon* _weapon = nullptr;

    std::string pClassToString(PlayerClass pClass);
};