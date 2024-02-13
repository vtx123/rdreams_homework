#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
    virtual int getPower(Tribe monsterTribeModifier) const { return getBasePower(); }
    virtual int getBasePower() const { return 0; }

    void setName(const std::string& name) { m_name = name; }
    const std::string getName() const { return m_name; }
    virtual std::string getFullInfo() const = 0;

protected:
    std::string m_name;
    //other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
    Weapon(const std::string& name, int power)
    {
        setName(name);
        m_power = power;
    }

    int getBasePower() const override
    {
        return m_power;
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
    }

protected:
    int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
    UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {
        case Tribe::Undead:
            return getBasePower() * 2;
        case Tribe::Human:
        case Tribe::Zombie:
        default:
            return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
    }
};

//TODO: Add new Item type with unique properties
class BioWeapon : public Weapon
{
public:
    BioWeapon(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {
            case Tribe::Human:
            case Tribe::Animal:
            case Tribe::Plant:
                return getBasePower() * 2;
            case Tribe::Undead:
            case Tribe::Zombie:
            case Tribe::Robot:
            case Tribe::God:
            default:
                return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs HUMAN | ANIMAL | PLANT!\n";
    }
};
class RoboWeapon : public Weapon
{
public:
    RoboWeapon(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {

            case Tribe::Robot:
                return getBasePower() * 2;
            case Tribe::Human:
            case Tribe::Animal:
            case Tribe::Plant:
            case Tribe::Undead:
            case Tribe::Zombie:
            case Tribe::God:
            default:
                return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs ROBOT!\n";
    }
};

class GodWeapon : public Weapon
{
public:
    GodWeapon(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {
            case Tribe::Human:
            case Tribe::Animal:
            case Tribe::Plant:
            case Tribe::Undead:
            case Tribe::Zombie:
                return getBasePower();
            case Tribe::God:
                return getBasePower() * 2;
            default:
                return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs GOD blocked Leveling!\n";
    }
};
