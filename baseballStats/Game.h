#ifndef BASEBALL_CPLUS_GAME_H
#define BASEBALL_CPLUS_GAME_H

#include "Player.h"
#include "Base.h"

#include <random>

class Game {
public:
    Game(teamPtr team1, teamPtr team2);

    void start();
    bool probabilityResult(int var, int &againts);
    void attack(teamPtr &attackTeam, teamPtr &defenceTeam);
    void result();

private:
    teamPtr m_team1 = {};
    teamPtr m_team2 = {};
    int m_inning = 0;
    int m_outs = 0;

    basePtr m_base1 = {};
    basePtr m_base2 = {};
    basePtr m_base3 = {};
    basePtr m_base_home = {};
};

#endif //BASEBALL_CPLUS_GAME_H
