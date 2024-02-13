#include <fstream>
#include <iostream>
#include "ItemDeck.h"

#include "Item.h"

ItemDeck::ItemDeck()
{
    //TODO: Move item's database to file in format:
    // type;name; additional if needed params for the type
    //For example:
    //UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

    //TODO: Setup more items of diferent types
//    m_itemsDataBase =
//    { new Weapon{"The Sword of DOOM", 5},
//    new UndeadWeapon{"Stinky knife", 2},
//    new UndeadWeapon{"Holy grenade", 4} };

    loadFromFile("items.txt");
}

ItemDeck::~ItemDeck()
{
    //TODO: FREE MEMORY
}

std::vector<Item*> ItemDeck::generateItems() const
{
    //TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
    return { m_itemsDataBase[std::rand() % m_itemsDataBase.size()],
             m_itemsDataBase[std::rand() % m_itemsDataBase.size()] };
}

void ItemDeck::loadFromFile(const std::string& fileName) {
    std::fstream fin(fileName);
    std::string ItemType, ItemName, line;
    int power;


//    while (fin >> ItemType) { // std::getline(fin, ItemType, ';')
    while (std::getline(fin, line, '\n')) { //
        std::getline(fin, ItemType, ';');
        std::getline(fin, ItemName, ';');
        fin >> power;
        if(ItemType == "Weapon")
        {
            m_itemsDataBase.push_back(new Weapon{ItemName, power});
        } else if (ItemType == "UndeadWeapon")
        {
            m_itemsDataBase.push_back(new UndeadWeapon{ItemName, power});
        } else if (ItemType == "BioWeapon")
        {
            m_itemsDataBase.push_back(new BioWeapon{ItemName, power});
        } else if (ItemType == "RoboWeapon")
        {
            m_itemsDataBase.push_back(new RoboWeapon{ItemName, power});
        } else if (ItemType == "GodWeapon")
        {
            m_itemsDataBase.push_back(new GodWeapon{ItemName, power});
        }
    }
}
