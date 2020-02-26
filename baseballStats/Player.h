#ifndef BASEBALL_CPLUS_PLAYER_H
#define BASEBALL_CPLUS_PLAYER_H

#include <memory>
#include <vector>

#include "Skills.h"
#include "Bases.h"
#include "IRandomize.h"

class Player {
public:
    Batting batting = {};
    Fielding fielding = {};
    BaseRunning baseRunning = {};
};

class Pitcher : public Player {
public:
    int pitch();
private:
    std::vector<int> m_pitch = {200, 150};
};

#endif //BASEBALL_CPLUS_PLAYER_H
