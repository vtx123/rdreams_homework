#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
    //This const values can be moved later into a config file
    //so they can be modified more granuarily on the go(by other programmers or designers) without need to modify code
    if (distance > 2000)
    {
        return 0.2f;
    }
    if (distance > 1000)
    {
        return 1.5f;
    }
    if (distance > 300)
    {
        return 5.0f;
    }
    return 1.0f;
}