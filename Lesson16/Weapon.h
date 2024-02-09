#pragma once
#include <iostream>

class Weapon {
public:
    Weapon(std::string name, int damage, int range);
    ~Weapon();

    void printWeaponInfo();

private:
    std::string _name = "";
    int _damage = 0;
    int _range = 0;
};