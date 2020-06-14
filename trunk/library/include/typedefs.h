//
// Created by student on 14.06.2020.
//

#ifndef GAMEBAJA_TYPEDEFS_H
#define GAMEBAJA_TYPEDEFS_H

#include <memory>

class Unit;
class Pillar;
class Player;
class Hand;
class PillarsArray;
class Play;
class Battlefield;
class Strategy;
class HumanPlayer;

typedef std::shared_ptr<Strategy> StrategyPtr;
typedef std::shared_ptr<HumanPlayer> HumanPlayerPtr;
typedef std::shared_ptr<Unit> UnitPtr;
typedef std::shared_ptr<Pillar> PillarPtr;
typedef std::shared_ptr<Player> PlayerPtr;


#endif //GAMEBAJA_TYPEDEFS_H
