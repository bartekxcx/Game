//
// Created by student on 04.06.2020.
//

#include "Player/HumanPlayer.h"
#include <iostream>
#include "Strategy.h"
#include <memory>

HumanPlayer::HumanPlayer(const std::string &nickname, Play *playerPlay) : Player(nickname, playerPlay) {
    std::cout<<"Stworzony gracz ludzki\n";
}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::decision() {
    std::cout<<"\nTura gracza: "<<getNickname()<<std::endl;
    while(getPlayerActions()>0) {
        try {
            Action action = strategy->decision(shared_from_this());
            switch (action) {
                case ATTACK:
                    strategy->attack(getPlayerBoard(), getPlayerPlay());
                    break;
                case TRADECARDS:
                    strategy->trade_cards(getPlayerHand());
                    break;
                case PUTCARD:
                    strategy->put_card(getPlayerHand(), getPlayerBoard());
                    break;
                case DRAWCARD:
                    strategy->draw_card(getPlayerHand());
                    break;
                case MOVEONBOARD:
                    strategy->move_onboard(getPlayerBoard());
                    break;
            }
        } catch (StrategyException &e) {
            std::cout << e.what() << std::endl;
            setPlayerActions(getPlayerActions() + 1);
        }

        setPlayerActions(getPlayerActions() - 1);
    }
}
