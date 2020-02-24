#ifndef BASEBALL_CPLUS_GAME_H
#define BASEBALL_CPLUS_GAME_H

#include "Player.h"
#include "Bases.h"
#include "Types.h"

#include <random>

class Game {
public:
    Game(teamPtr team1, teamPtr team2);

    void start();
    void attack(teamPtr &attackTeam, teamPtr &defenceTeam);
    void result();

private:
    teamPtr m_team1 = {};
    teamPtr m_team2 = {};
    int m_inning = 0;
    int m_outs = 0;

    basePtr m_bases = {};
};

#endif //BASEBALL_CPLUS_GAME_H
