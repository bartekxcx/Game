//
// Created by student on 13.06.2020.
//

#include <Player/HumanPlayer.h>
#include "Strategy.h"
#include <iostream>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>
#include "Battlefield.h"
#include "Hand.h"




Action Strategy::decision(HumanPlayerPtr) {
    int action;
    // Wyswietlenie stanu planszy
    std::cout<<"What do you want to do?"<<std::endl;
    std::cout<<"1. Attack, 2. Draw card, 3. Move card on board, 4. Put card on battlefield, 5. Trade cards"<<std::endl;
    std::cin>>action;
    switch(action)
    {
        case 1:
            return ATTACK;
            break;
        case 2:
            return DRAWCARD;
            break;
        case 3:
            return MOVEONBOARD;
            break;
        case 4:
            return PUTCARD;
            break;
        case 5:
            return TRADECARDS;
            break;
        default:
            throw StrategyException ("Wrong option");
    }
}

void Strategy::move_onboard(Battlefield* player_board) {
    int card_number, position;
    std::cout<<"What card do you want to move? (1-5) "<<std::endl;
    std::cin>>card_number;
    if(player_board->getCard(card_number-1)== nullptr) throw StrategyException("there is no card");
    std::cout<<"Where? (1-5) "<<std::endl;
    std::cin>>position;
    if(player_board->getCard(position-1)!=nullptr) throw StrategyException("There is a card on this position");
    player_board->getCard(card_number-1)->setPosition(position-1);
}

void Strategy::put_card(Hand* player_hand, Battlefield* player_board) {
    int card_number, position;
    std::cout<<"What card do you want to put? (1-5)"<<std::endl;
    std::cin>>card_number;
    if(player_hand->getCard(card_number-1)== nullptr) throw StrategyException("there is no card");
    std::cout<<"Where? (1-5) "<<std::endl;
    std::cin>>position;
    if(player_board->getCard(position-1)!=nullptr) throw StrategyException("There is a card on this position");
    player_board->setCard(position-1, player_hand->getCard(card_number-1));
    player_hand->setCard(card_number-1, nullptr);
}

void Strategy::draw_card(Hand* player_hand) {
    for(int i=0; i<5; i++)
    {
        if(player_hand->getCard(i)==nullptr)
        {
            UnitPtr newCard= RandomCard::random_card(i);
            player_hand->setCard(i, newCard);
            return;
        }
    }
    throw StrategyException("You already have 5 cards");
}

void Strategy::trade_cards(Hand * player_hand) {
    for(int i=0; i<5; i++)
    {
        if(player_hand->getCard(i)!=nullptr)
        {
            UnitPtr newCard= RandomCard::random_card(i);
            player_hand->setCard(i, newCard);
        }
    }
}

void Strategy::attack(Battlefield* player_board, Play* player_play) {
    int choice;
    std::cout<<"Using which card you want to attack? (1-5) "<<std::endl;
    std::cin>>choice;
    if(player_board->getCard(choice-1)==nullptr) throw StrategyException("There is no card");
    player_board->getCard(choice-1)->attack(player_play);
}



