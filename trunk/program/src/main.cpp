#include <iostream>
#include "Game.h"
#include "Play.h"
#include "Hand.h"
#include "Battlefield.h"
#include "Player/Player.h"
#include "Player/ComputerPlayer.h"
#include "Player/HumanPlayer.h"
#include "Unit/Unit.h"
#include "Unit/Warrior.h"
#include "Unit/Archer.h"
#include "Unit/Thief.h"
#include "Unit/Medic.h"
#include "Pillar/PillarsArray.h"
#include "Pillar/Pillar.h"
#include "Pillar/RedPillar.h"
#include "Pillar/BluePillar.h"
#include "Pillar/GreenPillar.h"
#include <ctime>
#include <typeinfo>

int main() {

    srand( time( NULL ) );

    Game *game=new Game();
    Play *playtest=game->new_play();

    std::cout<<playtest->getPlayInfo();
    playtest->getPlayer()->decision();

    return 0;


}
