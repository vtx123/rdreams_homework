#include "Player.h"

Player::Player(const std::string &name, int health, PlayerClass pClass) :_name(name), _health(health), _pClass(pClass) {
    if (health < 0) {
        health = 1;
    }

    if (_pClass == PlayerClass::DEFAULT) {
        _pClass = PlayerClass::SUPPORT;
    }
}

void Player::setWeapon(Weapon* weapon) {
    _weapon = weapon;
}

Weapon* Player::getWeapon() const {
    return _weapon;
}

std::string Player::pClassToString(PlayerClass pClass) {
    switch (pClass)
    {
    case PlayerClass::DEFAULT:
        return "Empty";
        break;
    case PlayerClass::ASSAULT:
        return "Assault";
        break;
    case PlayerClass::SUPPORT:
        return "Support";
        break;
    case PlayerClass::SNIPER:
        return "Sniper";
        break;
    case PlayerClass::MEDIC:
        return "Medic";
        break;
    default:
        return "Empty";
        break;
    }
}

std::string Player::getName() {
    return _name;
}
void Player::printPlayerInfo() {
    std::cout << "Player info: " << std::endl;
    std::cout << "   Name: " << _name << std::endl;
    std::cout << "   Health: " << _health << std::endl;
    std::cout << "   Class: " << pClassToString(_pClass) << std::endl;
    _weapon->printWeaponInfo();
}

Player::~Player() {

}