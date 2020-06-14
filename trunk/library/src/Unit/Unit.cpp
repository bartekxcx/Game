//
// Created by student on 04.06.2020.
//

#include "../../include/Unit/Unit.h"
#include <sstream>

Unit::Unit( int position) :position(position){
    if(position>4)
    {
        throw UnitException("This position doesn't exist");
    }
    on_board=false;
}

Unit::~Unit() {
delete this;
}

int Unit::getHealth() const {
    return health;
}

void Unit::setHealth(int health) {
    if(health<=0) this->~Unit();
    Unit::health = health;
}

int Unit::getPosition() const {
    return position;
}

void Unit::setPosition(unsigned int position) {
    if(position>4) {
        throw UnitException("This position doesn't exist");
    }
    Unit::position = position;
}

bool Unit::isOnBoard() const {
    return on_board;
}

void Unit::setOnBoard() {
    on_board = !on_board;
}

int Unit::getAttackPower() const {
    return attack_power;
}

const std::string &Unit::getAbility() const {
    return ability;
}

void Unit::move(int) {

}

void Unit::attack(Play* play) {
    UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(getPosition());
    if(enemy!=nullptr)
    {
        int newHealth= enemy->getHealth()-getAttackPower();
        enemy->setHealth(newHealth);
    } else{
        PillarPtr enemypillar=play->getEnemyPlayer()->getPlayerPillars()->getPillar(getPosition());
        if(enemypillar!=nullptr)
        {
            int newHealth= enemypillar->getHealth()-getAttackPower();
            enemypillar->setHealth(newHealth);
            enemypillar->defend(play);
        }
    }


}

std::string Unit::get_unit_info() {
    std::ostringstream sout;
    sout<<"Zycie: "<<getHealth()<<" ";
    sout<<"Atak: "<<getAttackPower()<<" ";
    sout<<"Specjalna umiejestnosc: "<<getAbility()<<" ";
    sout<<std::endl;
    return sout.str();
}

