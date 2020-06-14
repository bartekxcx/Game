//
// Created by student on 04.06.2020.
//

#include "../../include/Player/Player.h"
#include "Hand.h"
#include "Battlefield.h"
#include "Pillar/PillarsArray.h"
#include <sstream>

Player::Player(const std::string &nickname, Play *playerPlay) : nickname(nickname), player_play(playerPlay) {

    if (playerPlay== nullptr) {
        throw PlayerException("Cannot create Player without play");
    }
    player_board = new Battlefield();
    player_hand = new Hand();
    player_pillars = new PillarsArray();
    player_actions= 3;

}

Player::~Player() {

}

int Player::getPlayerActions() const {
    return player_actions;
}

void Player::setPlayerActions(unsigned int playerActions) {
    if(playerActions>4)
    {
        throw PlayerException("Too many actions");
    }
    player_actions = playerActions;
}

int Player::getChoice() const {
    return choice;
}

void Player::setChoice(unsigned int choice) {
    if(choice>=2000) //nie wiemy ile jest akcji do wyboru
    {
        throw PlayerException("Wrong choice");
    }
    Player::choice = choice;
}

Hand *Player::getPlayerHand() const {
    return player_hand;
}

Battlefield *Player::getPlayerBoard() const {
    return player_board;
}

PillarsArray *Player::getPlayerPillars() const {
    return player_pillars;
}

const std::string &Player::getNickname() const {
    return nickname;
}

Play *Player::getPlayerPlay() const {
    return player_play;
}

std::string Player::getPlayerInfo() {
    std::ostringstream sout;
    sout << getNickname()<<std::endl;
    sout << player_hand->getCardsInfo();
    sout << player_board->getCardsInfo();
    sout << player_pillars->getPillarsInfo();
    return sout.str();


}

void Player::decision() {

}
