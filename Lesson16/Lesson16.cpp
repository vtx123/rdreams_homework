// Lesson 16 1
#include <iostream>
#include "Rectangle.h"
#include "Player.h"
#include "Team.h"

int main()
{
    Rectangle *rect1 = new Rectangle();
    Rectangle *rect2 = new Rectangle(50, 60);

    std::cout << "Area of 1 rect = " << rect1->getArea() << std::endl;
    std::cout << "Area of 1 rect = " << rect1->getPerimeter() << std::endl;
    std::cout << "Area of 2 rect = " << rect2->getArea() << std::endl;
    std::cout << "Area of 2 rect = " << rect2->getPerimeter() << std::endl << std::endl;

    Weapon *wRifle = new Weapon("rifle", 200, 1000);
    Weapon *wPistol = new Weapon("pistol", 20, 200);
    Weapon *wMG = new Weapon("machine gun", 100, 500);

    Player* p1 = new Player("Dasha", 100, PlayerClass::MEDIC);
    p1->setWeapon(wPistol);

    Player* p2 = new Player("John", 200, PlayerClass::ASSAULT);
    p2->setWeapon(wMG);

    Player* p3 = new Player("Cano", 50, PlayerClass::SNIPER);
    p3->setWeapon(wRifle);

    Team* t1 = new Team("Sprit");
    Team* t2 = new Team("Number One");

    t1->addPlayer(p1);
    t1->addPlayer(p2);
    t2->addPlayer(p2);
    t2->addPlayer(p3);

    t2->removePlayer(p2);

    p1->printPlayerInfo();
    p2->printPlayerInfo();
    p3->printPlayerInfo();

    t1->printTeamInfo();
    t2->printTeamInfo();

}
