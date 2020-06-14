//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_COMPUTERPLAYER_H
#define GAMEBAJA_COMPUTERPLAYER_H

#include "Player.h"


class ComputerPlayer : public Player{
public:
    ComputerPlayer(const std::string &nickname, Play *playerPlay);

    virtual ~ComputerPlayer();

   // virtual void decision() override;

};


#endif //GAMEBAJA_COMPUTERPLAYER_H
