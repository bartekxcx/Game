//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_ARCHER_H
#define GAMEBAJA_ARCHER_H


#include "Unit.h"

class Archer : public Unit{
public:
    Archer( int position);

    virtual ~Archer();

    virtual void attack(Play*) override ;

};


#endif //GAMEBAJA_ARCHER_H
