#include <functional>
#include <algorithm>
#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"

void Munchkin::removeModifierFromHand(){
    popModifier(rand() % m_modifiers.size());
}
void Munchkin::removeItemEquipped(bool maxPower){
    if(maxPower){
        if (m_items.size() > 0) {
            m_items.pop_back();
        }
    }
    // TODO: remove item by smth else
}

void Munchkin::removeItemByIndex(int idx){
    if (idx >= m_items.size() || idx < 0)
    {
        return;
    }
    Item* item = m_items[idx];
    m_items.erase(m_items.begin() + idx);
}

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        for(auto i: m_items){
            if(i->isLevelUpBlocked()) {
                return;
            }
        }
        m_level += levels;
    }
}

void Munchkin::addModifier(Modifier* modifier){
    m_modifiers.push_back(modifier);
}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
    std::sort(m_items.begin(), m_items.end(), [](Item *a, Item *b)
              {
                  return a->getBasePower() < b->getBasePower();
              });
}

void Munchkin::setItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];

    //Erase-remove idiom can be used as we don't really care about
    //internal order of the elements
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}
