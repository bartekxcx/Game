//
// Created by student on 04.06.2020.
//

#include "Player/ComputerPlayer.h"
#include <iostream>

ComputerPlayer::ComputerPlayer(const std::string &nickname, Play *playerPlay) : Player(nickname, playerPlay) {
    std::cout<<"Stworzony gracz komputerowy\n";
}

ComputerPlayer::~ComputerPlayer() {

}
