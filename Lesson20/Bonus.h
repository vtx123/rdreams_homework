#pragma once
#include <string>

//forwad declaration
class Munchkin;
class DeckHelper;

class Bonus
{
public:
    virtual void apply(Munchkin* munchkin, DeckHelper &dh) = 0;

    virtual std::string getFullInfo() const = 0;
};

//Add a card to hand(modifier)
class Bonus_AddModifier : public Bonus
{
public:
    void apply(Munchkin* munchkin, DeckHelper &dh) override;
    
    virtual std::string getFullInfo() const override { return "[Add CARD to Hand]"; }
};

//Add item to Outfit
class Bonus_AddItem : public Bonus
{
public:
    void apply(Munchkin* munchkin, DeckHelper &dh) override;
    
    virtual std::string getFullInfo() const override { return "[Add Item to OUTFIT]"; }
};
