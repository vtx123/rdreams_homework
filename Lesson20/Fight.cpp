#include "Fight.h"

#include "Item.h"
#include "Modifier.h"
#include "Munchkin.h"
#include "Monster.h"
#include "Runaway.h"
#include "DeckHelper.h"
#include <assert.h>

void Fight::start()
{
    //Setup initial state
    m_result = FightResult::InProgress;

    calculateMunchkinPower();
    calculateMonsterPower();
}

void Fight::applyModifier(int choice)
{
    Modifier* modifier = m_munchkin->popModifier(choice);
    
    if (modifier == nullptr)
    {
        //Give some assert/warning in debug to a user that modifier is null so something is wrong
        assert(modifier == nullptr);
        return;
    }

    modifier->apply(m_munchkin, m_monster);

    m_MunchkinPower += modifier->getMunchkinModifier();
    m_monsterPower += modifier->getMonsterModifier();
}

void Fight::runawayFlow()
{
    Runaway* policy = m_monster->getRunawayPolicy();
    policy->apply(m_munchkin);

    m_result = FightResult::MonsterWon;
}

void Fight::victoryFlow(DeckHelper& deckHelper)
{
    //#TODO: Implement at LEAST ONE victory policy similar to runaway policy
    //Possible policies are:
    //  Add new cards to hand
    //  Generate new Outfit items???
    //  Increase Level by 0,1,2

    m_munchkin->updateLevelBy(1);
    
    Bonus* bonus = m_monster->getBonusPolicy();
    if(bonus != nullptr){
        bonus->apply(m_munchkin, deckHelper);
    }
    
    
    m_result = FightResult::MunchkinWon;
}

void Fight::calculateMunchkinPower()
{
    m_MunchkinPower += m_munchkin->getLevel();
    for (Item* item : m_munchkin->getItems())
    {
        m_MunchkinPower += item->getPower(m_monster->getTribe());
    }
}

void Fight::calculateMonsterPower()
{
    m_monsterPower = m_monster->getLevel();
}
