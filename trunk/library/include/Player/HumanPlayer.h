//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_HUMANPLAYER_H
#define GAMEBAJA_HUMANPLAYER_H

#include "Player.h"

enum Action{
    ATTACK, DRAWCARD, MOVEONBOARD, PUTCARD, TRADECARDS
};

class StrategyException : public std::logic_error
{
public:
    explicit StrategyException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

class HumanPlayer : public Player, public std::enable_shared_from_this<HumanPlayer>{
private:
    StrategyPtr strategy;
public:
    HumanPlayer(const std::string &nickname, Play *playerPlay);

    virtual ~HumanPlayer();

    virtual void decision() override;

};



#endif //GAMEBAJA_HUMANPLAYER_H
