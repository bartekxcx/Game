//
// Created by student on 04.06.2020.
//

#include "../include/Game.h"
#include <iostream>
#include "Play.h"
#include <string>

Game::Game() {}

Game::~Game() {

}

void Game::load_game(Play) {

}

void Game::exit() {

}

Play* Game::new_play() {
    int how_many_human_players;
    std::string nickname1;
    std::string nickname2;
    std::cout<<"Witaj w grze zespolu Baja"<<std::endl;
    std::cout<<"Wprowadz liczbe graczy ludzkich: "<<std::endl;
    std::cin>>how_many_human_players;
    std::cout<<"Podaj nick pierwszego gracza: "<<std::endl;
    std::cin>>nickname1;
    std::cout<<"Podaj nick drugiego gracza: "<<std::endl;
    std::cin>>nickname2;
    Play *play= new Play( how_many_human_players,nickname1,nickname2);
    return play;
}
