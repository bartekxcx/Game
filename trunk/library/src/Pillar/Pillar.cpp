//
// Created by student on 04.06.2020.
//

#include "Pillar/Pillar.h"
#include <string>
#include <sstream>


Pillar::Pillar(int position):position(position)  {

    health=15;


}
int Pillar::getHealth()
{
    return health;
}
void Pillar::setHealth(unsigned int new_health)
{
    if(new_health==0) this->~Pillar();
    health=new_health;
}
std::string Pillar::getAbility()
{
    return ability;
}

std::string Pillar::getPillarInfo(){
    std::ostringstream sout;
    sout<<"Zycie: "<<getHealth()<<" ";
    sout<<"Specjalna umiejetnosc: "<<getAbility();
    sout<<"Pozycja: "<<getPosition()<<std::endl;
    return sout.str();
}

Pillar::~Pillar() {

}

void Pillar::defend(Play* play) {

}

int Pillar::getPosition() {
    return position;
}

//void defend();
