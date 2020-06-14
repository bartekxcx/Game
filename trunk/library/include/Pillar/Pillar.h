//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_PILLAR_H
#define GAMEBAJA_PILLAR_H
#include <string>
#include <memory>
#include "typedefs.h"


class Pillar {
protected:
    unsigned int health;
    std::string ability;
    int position;
public:
    int getHealth();
    void setHealth(unsigned int new_health);
    std::string getAbility();
    std::string getPillarInfo();
    Pillar(int position);
    ~Pillar();
    int getPosition();
    virtual void defend(Play* play);

};


#endif //GAMEBAJA_PILLAR_H
