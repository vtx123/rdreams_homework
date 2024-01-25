#include <string>
#include <vector>
//#include <ctime>
#include <iostream>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
    srand(time(nullptr));
    //Game cycle
    Player player1("OnePunchMan", new SniperRifle);
    Player player2("JohnCena", new Axe, new DefenderClass);
    //TODO: Other players with other weapons and classes to properly cover different test-cases
    // SniperRifle
    Player p1("Defender-Sniper", new SniperRifle, new DefenderClass);
    Player p2("Attaker-Sniper", new SniperRifle, new AttackerClass);
    Player p3("Lucky-Sniper", new SniperRifle, new LuckyManClass);
    Player p4("Berserk-Sniper", new SniperRifle, new BerserkClass);
    // Pistol
    Player p5("Defender-Pistol", new Pistol, new DefenderClass);
    Player p6("Attaker-Pistol", new Pistol, new AttackerClass);
    Player p7("Lucky-Pistol", new Pistol, new LuckyManClass);
    Player p8("Berserk-Pistol", new Pistol, new BerserkClass);
    // AssaultRifle
    Player p9("Defender-Assault", new AssaultRifle, new DefenderClass);
    Player p10("Attaker-Assault", new AssaultRifle, new AttackerClass);
    Player p11("Lucky-Assault", new AssaultRifle, new LuckyManClass);
    Player p12("Berserk-Assault", new AssaultRifle, new BerserkClass);
    // BareHand
    Player p13("Defender-Bare", new BareHand, new DefenderClass);
    Player p14("Attaker-Bare", new BareHand, new AttackerClass);
    Player p15("Lucky-Bare", new BareHand, new LuckyManClass);
    Player p16("Berserk-Bare", new BareHand, new BerserkClass);
    // Axe
    Player p17("Defender-Axe", new Axe, new DefenderClass);
    Player p18("Attaker-Axe", new Axe, new AttackerClass);
    Player p19("Lucky-Axe", new Axe, new LuckyManClass);
    Player p20("Berserk-Axe", new Axe, new BerserkClass);

    std::vector<Player*> players{ &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, &p16, &p17, &p18, &p19, &p20 };

    // Modeling battle field
    bool run = true;
    int randPlayerIndex1 = 0;
    int randPlayerIndex2 = 0;
    const int winnersCount = 3;
    int aliveCounter = players.size();
    while (aliveCounter > winnersCount) { // one turn (1 player attack another)

        randPlayerIndex1 = (1 + rand() % 19);
        while (players[randPlayerIndex1]->isEliminated()) { // random choose 1 player = damage owner
            randPlayerIndex1 = (randPlayerIndex1 + 1) % (players.size() - 1);
        }

        randPlayerIndex2 = (1 + rand() % 19);
        while (players[randPlayerIndex2]->isEliminated()) { // random choose 2 player = damage taker
            randPlayerIndex2 = (randPlayerIndex2 + 1) % (players.size() - 1);
        }

        players[randPlayerIndex1]->attack(*players[randPlayerIndex2], 100 + rand() % 1900);
        std::cout << "-------------------------------------------------------------------------" << std::endl;

        aliveCounter = 0; // check alive players on the battle field
        for (Player* player : players) {
            if (!player->isEliminated()) {
                aliveCounter++;
            }
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "TOP " << winnersCount << " WINNERS! Who is still alive: " << std::endl;
    for (int i = 0; i < players.size(); i++) {
        if (!players[i]->isEliminated()) {
            std::cout << players[i]->getName() << ": " << players[i]->getHealth() << " HP" << std::endl;
        }
    }

    return 0;
}