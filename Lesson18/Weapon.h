#pragma once
#include <string>

class Weapon
{
public:
    //Feel free to add other properties
    //Or use another approach for damage calculation:
    //health, stamina, weight, level, speed or whatever you have in mind.
    virtual int getDamageRate(int distance) const = 0;
    virtual std::string getName() const = 0;
private:
    virtual float getEffectiveRange(int distance) const = 0;
    virtual float getDamageLevel() const = 0;
};

class RangedWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override { return static_cast<int>(getEffectiveRange(distance) * getDamageLevel() + getPrecision(distance) * 10); }
    std::string getName() const override { return "-"; }
    //protected means this method is not accessible from outside but is accessible by children classes
protected:
    //Default value
    virtual float getPrecision(int distance) const { return 1.0f; }
    float getEffectiveRange(int distance) const override { 
        if (distance > 2000) {
            return 0.9f;
        }else if (distance > 1500) {
            return 1.5f;
        }
        else if (distance > 500) {
            return 1.0f;
        }
        else if (distance > 100) {
            return 0.3f;
        }
        else {
            return 0.1f;
        }
    }
    virtual float getDamageLevel() const { return 10.0f; }
};

class SniperRifle : public RangedWeapon
{
public:
    std::string getName() const override { return "SniperRifle"; }
protected:
    float getDamageLevel() const override { return 10.0f; }
    virtual float getPrecision(int distance) const override;
};

//TODO
class Pistol : public RangedWeapon
{
public:
    std::string getName() const override { return "Pistol"; }
protected:
    float getDamageLevel() const override { return 2.0f; }
};

//TODO
class AssaultRifle : public RangedWeapon
{
public:
    std::string getName() const override { return "AssaultRifle"; }
protected:
    float getDamageLevel() const override { return 7.0f; }
};

class MeleeWeapon : public Weapon
{
public:
    virtual int getDamageRate(int distance) const override
    {
        //TODO: Implement your custom unique logic
        //Probably shouldn't be affected by distance (or at least only two possible states:
        //either in-reach or out-of-reach for this particular melee weapon
        return getEffectiveRange(distance) * getDamageLevel();
    }
    float getEffectiveRange(int distance) const override {
        if (distance > 600) {
            return 0.0f;
        }
        else if (distance > 500) {
            return 0.8f;
        }
        else if (distance > 100) {
            return 1.5f;
        }
        else {
            return 1.0f;
        }
    }
    std::string getName() const override { return "-"; }
protected:
    virtual float getDamageLevel() const override { return 5.0f; }
};

class BareHand : public MeleeWeapon
{
    //TODO
public:
    std::string getName() const override { return "BareHand"; }
protected:
    float getDamageLevel() const override { return 4.0f; }
};

class Axe : public MeleeWeapon
{
    //TODO
public:
    std::string getName() const override { return "Axe"; }
protected:
    float getDamageLevel() const override { return 8.0f; }
};
