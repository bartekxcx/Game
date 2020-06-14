//
// Created by student on 04.06.2020.
//

#include "Pillar/PillarsArray.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Pillar/Pillar.h"
#include "Pillar/BluePillar.h"
#include "Pillar/RedPillar.h"
#include "Pillar/GreenPillar.h"


PillarsArray::PillarsArray()
{
    srand( time( NULL ) );
    for(int i=0; i<5; i++)
    {
        int x=(std::rand()%3)+1;
        if(x==1) wall_of_pillars[i]=std::make_shared<BluePillar>(i);
        else if (x==2) wall_of_pillars[i]=std::make_shared<RedPillar>(i);
        else wall_of_pillars[i]=std::make_shared<GreenPillar>(i);
    }
}

std::string PillarsArray::getPillarsInfo()
{
    std::ostringstream sout;
    for(unsigned int i=0;i<5;i++) {
        if(wall_of_pillars[i]==nullptr) sout<<"Pillar destroyed"<<std::endl;
        else{
            sout << "Zycie: " + std::to_string(wall_of_pillars[i]->getHealth()) + " ";
            sout << "Specjalna umiejetnosc: " + wall_of_pillars[i]->getAbility() << std::endl;
        }
    }
    return sout.str();
}
PillarPtr PillarsArray::getPillar(int pillar_number)
{
    if(pillar_number>4)
    {
        throw PillarsArrayException("This pillar doesn't exist");
    }
    return wall_of_pillars[pillar_number];
}

PillarsArray::~PillarsArray() {

}
