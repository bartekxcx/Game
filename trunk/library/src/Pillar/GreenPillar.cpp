//
// Created by student on 04.06.2020.
//

#include "Pillar/GreenPillar.h"
#include "Play.h"
#include "Battlefield.h"
#include "Unit/Unit.h"

GreenPillar::GreenPillar(int position) : Pillar(position) {
    ability="Green";
}

GreenPillar::~GreenPillar() {

}

void GreenPillar::defend(Play* play) {
    for(unsigned int i = 0; i<5; i++)
    {
        UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(i);
        enemy->setHealth(enemy->getHealth()-1);
    }

}


