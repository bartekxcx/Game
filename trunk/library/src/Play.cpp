//
// Created by student on 04.06.2020.
//

#include "../include/Play.h"
#include "Player/Player.h"
#include "Player/HumanPlayer.h"
#include "Player/ComputerPlayer.h"
#include "Battlefield.h"
#include <sstream>


Play::Play(unsigned int how_many_human_players,std::string nickname1,std::string nickname2) : how_many_human_players(how_many_human_players) {

    if(how_many_human_players>2)
    {
        throw PlayException("Too many human players");
    }
    if (how_many_human_players == 2) {
        player1 = std::make_shared<HumanPlayer>(nickname1, this);
        player2 = std::make_shared<HumanPlayer>( nickname2, this);
    }
    if (how_many_human_players == 1) {
        player1 = std::make_shared<HumanPlayer>( nickname1, this);
        player2 = std::make_shared<ComputerPlayer>( nickname2, this);
    }
    if (how_many_human_players == 0) {
        player1 = std::make_shared<ComputerPlayer>( nickname1, this);
        player2 = std::make_shared<ComputerPlayer>( nickname2, this);
    }
    whose_turn=true;
    check_win=false;
}

Play::~Play() {

}

bool Play::isTurnPlayer1() const {
    return whose_turn;
}

void Play::setWhoseTurn() {
    whose_turn = !whose_turn;
}

PlayerPtr Play::getPlayer() const {
    if (isTurnPlayer1()) return player1;
    return player2;
}

PlayerPtr Play::getEnemyPlayer() const {
    if (isTurnPlayer1()) return player2;
    return player1;
}

void Play::save() {

}

std::string Play::getPlayInfo() {
    std::ostringstream sout;
    sout << player1->getPlayerInfo();
    sout << player2->getPlayerInfo();
    return sout.str();
}

void Play::play() {
    while(!check_win)
    {
//        getPlayer()->decision();
        setWhoseTurn();
    }

}

bool Play::isCheckwin() const {
    return check_win;
}

void Play::setCheckwin() {
    check_win=!check_win;
}

void Play::decision() {

}


