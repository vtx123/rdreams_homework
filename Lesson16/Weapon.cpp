#include "Weapon.h"

Weapon::Weapon(std::string name, int damage, int range):_name(name), _damage(damage), _range(range) {

}

Weapon::~Weapon() {

}

void Weapon::printWeaponInfo() {
    std::cout << "Weapon info: " << std::endl;
    std::cout << "   Name: " << _name << std::endl;
    std::cout << "   Damage: " << _damage << std::endl;
    std::cout << "   Range: " << _range << std::endl;
}