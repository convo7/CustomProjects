#ifndef BASEBALL_CPLUS_PLAYER_H
#define BASEBALL_CPLUS_PLAYER_H


#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "Skills.h"
#include "Base.h"

class Team;
class Player;
class Pitcher;
class Base;

typedef std::shared_ptr<Team> teamPtr;
typedef std::shared_ptr<Player> playerPtr;
typedef std::shared_ptr<Pitcher> pitcherPtr;
typedef std::shared_ptr<Base> basePtr;

class Player {
public:
    Batting batting = {};
    Fielding fielding = {};
    BaseRunning baseRunning = {};
};

class Pitching {
public:
    int m_fastball = 300;
};

class Pitcher : public Player, public Pitching {
public:
    int throwPitch();
};

#endif //BASEBALL_CPLUS_PLAYER_H
