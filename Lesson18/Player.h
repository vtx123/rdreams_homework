#pragma once
#include <string>
#include "PlayerClass.h"
#include "Weapon.h"

class Player
{
public:
    Player(const std::string& name = "Auto Generated NameId", Weapon* weapon = new BareHand, PlayerClass* playerClass = new DefaultClass)
        : m_name(name), m_weapon(weapon), m_class(playerClass) {}
    ~Player();

    std::string getName() const { return m_name; }
    int getHealth() const { return m_health; }
    int getBaseDamage(int distance) const { return m_weapon->getDamageRate(distance); }

    void setWeapon(Weapon* weapon);
    void setPlayerClass(PlayerClass* playerClass);
    void setHealth(int health) { m_health = health; }
    void setDamage(int damage);
    bool isEliminated() const { return m_health <= 0; }

    void attack(Player& other, int distance);

private:
    int m_health = 100;
    std::string m_name;

    PlayerClass* m_class = nullptr;
    Weapon* m_weapon = nullptr;
};