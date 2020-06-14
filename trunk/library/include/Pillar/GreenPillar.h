//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_GREENPILLAR_H
#define GAMEBAJA_GREENPILLAR_H
#include "Pillar.h"

class GreenPillar : public Pillar{
public:
    GreenPillar(int position);

    virtual ~GreenPillar();
    virtual void defend(Play* play) override;

};


#endif //GAMEBAJA_GREENPILLAR_H
