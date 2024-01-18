#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
    //Game cycle
    Player player1("OnePunchMan", new SniperRifle);
    Player player2("JohnCena", new Axe, new DefenderClass);
    //TODO: Other players with other weapons and classes to properly cover different test-cases


    player1.attack(player2, 500);
    player1.attack(player2, 2000);
    player1.attack(player1, 300);
    player2.attack(player1, 100);
    player1.attack(player2, 500);

    return 0;
}