#include "Bonus.h"
#include "Munchkin.h"
#include "DeckHelper.h"

void Bonus_AddModifier::apply(Munchkin* munchkin, DeckHelper &dh) {
    munchkin->addModifier(dh.randomModifierFromDeck());
}

void Bonus_AddItem::apply(Munchkin* munchkin, DeckHelper &dh) {
    munchkin->addItem(dh.randomItemFromDeck());
}
