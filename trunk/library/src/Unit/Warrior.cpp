//
// Created by student on 04.06.2020.
//

#include "../../include/Unit/Warrior.h"

Warrior::Warrior( int position) : Unit(position) {
    health=7;
    attack_power=3;
    ability="Warrior";
}

Warrior::~Warrior() {
}

void Warrior::attack(Play* play) {
    Unit::attack(play);
    if(getPosition()>0)
    {
        UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(getPosition()-1);
        if(enemy!=nullptr)
        {
            int newHealth= enemy->getHealth()-getAttackPower();
            enemy->setHealth(newHealth);
        } else{
            PillarPtr enemypillar=play->getEnemyPlayer()->getPlayerPillars()->getPillar(getPosition()-1);
            if(enemypillar!=nullptr)
            {
                int newHealth= enemypillar->getHealth()-getAttackPower();
                enemypillar->setHealth(newHealth);
                enemypillar->defend(play);
            }
        }
    }
    if(getPosition()<4)
    {
        UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(getPosition()+1);
        if(enemy!=nullptr)
        {
            int newHealth= enemy->getHealth()-getAttackPower();
            enemy->setHealth(newHealth);
        } else{
            PillarPtr enemypillar=play->getEnemyPlayer()->getPlayerPillars()->getPillar(getPosition()+1);
            if(enemypillar!=nullptr)
            {
                int newHealth= enemypillar->getHealth()-getAttackPower();
                enemypillar->setHealth(newHealth);
                enemypillar->defend(play);
            }
        }
    }

}
