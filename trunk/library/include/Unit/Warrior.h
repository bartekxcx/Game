//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_WARRIOR_H
#define GAMEBAJA_WARRIOR_H


#include "Unit.h"

class Warrior : public Unit{
public:
    Warrior( int position);

    virtual ~Warrior();

    virtual void attack(Play*) override ;

};


#endif //GAMEBAJA_WARRIOR_H
