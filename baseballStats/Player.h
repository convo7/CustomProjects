#ifndef BASEBALL_CPLUS_PLAYER_H
#define BASEBALL_CPLUS_PLAYER_H

#include <memory>
#include <vector>

#include "Skills.h"
#include "Bases.h"
#include "IRandomize.h"
#include "Pitching.h"

class Player {
public:
    Batting batting = {};
    Fielding fielding = {};
    BaseRunning baseRunning = {};
};

class Pitcher : public Player, public Pitching {
};

#endif //BASEBALL_CPLUS_PLAYER_H
