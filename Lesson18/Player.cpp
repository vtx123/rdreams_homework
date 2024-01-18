#include "Player.h"
#include <iostream>

// aka RAII principle, see more here: 
// https://covemountainsoftware.com/2019/11/26/why-i-prefer-c-raii-all-the-things/
Player::~Player()
{
    delete m_class;
    delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
    delete m_weapon;
    m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
    delete m_class;
    m_class = playerClass;
}

void Player::attack(Player& other, int distance)
{
    if (isEliminated()) {
        std::cout << "Player " << getName() << " Died and can't attack!" <<
            " with weapon " << m_weapon->getName() << std::endl;
        return;
    }

    if (&other == this)
    {
        std::cout << "\n-------FRIENDLY FIRE!-------\n";
    }

    if (other.isEliminated())
    {
        std::cout << "Player " << other.getName() << " has been already eliminated!\n";
        return;
    }

    //More damage-related modifiers can be added here
    //TODO: Add miss-chance of the class into account
    int damage = 0;
    float missChance = (1 + rand() % 9) * 0.1;
    if (missChance > other.m_class->getMissChance()) {
        damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());

        std::cout << "Player " << getName() << " : " << m_health << "HP, with weapon [" << m_weapon->getName() 
            << "] --> attacked Player " << other.getName() << " on damage " << damage << std::endl;
    }
    else {
        std::cout << "Player " << getName() << " : " << m_health << "HP, with weapon [" << m_weapon->getName()
            << "] --> attacked Player " << other.getName() << " and MISS" << std::endl;
    }

    other.setDamage(damage);
}

void Player::setDamage(int damage) {
    m_health -= damage;

    std::cout << getName() << " Health left: " << m_health << std::endl;
    if (m_health <= 0)
    {
        m_health = 0;	//for consistency. For example UI may not support properly negative values

        std::cout << "Player " << getName() << " was eliminated!\n";
    }
}