//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_BLUEPILLAR_H
#define GAMEBAJA_BLUEPILLAR_H
#include "Pillar.h"

class BluePillar : public Pillar{
public:
    BluePillar(int position);

    virtual ~BluePillar();
    virtual void defend(Play* play) override;

};


#endif //GAMEBAJA_BLUEPILLAR_H
