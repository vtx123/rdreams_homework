#include <fstream>
#include <iostream>
#include "ItemDeck.h"

#include "Item.h"

ItemDeck::ItemDeck()
{
    loadFromFile("items.txt");
}

ItemDeck::~ItemDeck()
{
    //TODO: FREE MEMORY
    for ( int i = 0; i < m_itemsDataBase.size(); i++)
    {
        delete m_itemsDataBase[i];
    }
}

Item* ItemDeck::getItem()
{
    //TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
    auto val = m_itemsDataBase.back();
    m_itemsDataBase.pop_back();
    return val;
}

void ItemDeck::loadFromFile(const std::string& fileName) {
    std::fstream fin(fileName);
    std::string ItemType, ItemName, line;
    int power;

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
