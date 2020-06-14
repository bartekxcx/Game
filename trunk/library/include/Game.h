//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_GAME_H
#define GAMEBAJA_GAME_H

#include "typedefs.h"


class Game {
public:
    virtual ~Game();

    Game();

    void load_game(Play);
    void exit();
    Play* new_play();

};


#endif //GAMEBAJA_GAME_H
