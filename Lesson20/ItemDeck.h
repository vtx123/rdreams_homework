#pragma once
#include <vector>

class Item;

class ItemDeck
{
public:
    ItemDeck();
    ~ItemDeck();

    std::vector<Item*> generateItems() const;

private:
    void loadFromFile(const std::string& fileName);
    std::vector<Item*> m_itemsDataBase;
};
