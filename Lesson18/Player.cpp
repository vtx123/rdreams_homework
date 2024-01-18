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

void Player::attack(const Player& other, int distance)
{
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
    const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
    m_health -= damage;

    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
        " with damage " << damage << std::endl;

    std::cout << "Health left: " << m_health << std::endl;

    if (m_health <= 0)
    {
        m_health = 0;	//for consistency. For example UI may not support properly negative values

        std::cout << "Player " << other.getName() << " was eliminated!\n";
    }
}