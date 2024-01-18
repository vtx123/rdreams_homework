#pragma once

class Weapon
{
public:
    //Feel free to add other properties
    //Or use another approach for damage calculation:
    //health, stamina, weight, level, speed or whatever you have in mind.
    virtual int getDamageRate(int distance) const = 0;
};

class RangedWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

    //protected means this method is not accessible from outside but is accessible by children classes
protected:
    //Default value
    virtual float getPrecision(int distance) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon
{
protected:
    virtual float getPrecision(int distance) const override;
};

//TODO
class Pistol : public RangedWeapon
{

};

//TODO
class AssaultRifle : public RangedWeapon
{

};

class MeleeWeapon : public Weapon
{
public:
    virtual int getDamageRate(int distance) const override
    {
        //TODO: Implement your custom unique logic
        //Probably shouldn't be affected by distance (or at least only two possible states:
        //either in-reach or out-of-reach for this particular melee weapon
        return 10;
    }
};

class BareHand : public MeleeWeapon
{
    //TODO
};

class Axe : public MeleeWeapon
{
    //TODO
};
