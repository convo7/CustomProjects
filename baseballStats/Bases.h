#ifndef BASEBALL_CPLUS_BASE_H
#define BASEBALL_CPLUS_BASE_H

#include "Player.h"
#include "Team.h"
#include "Types.h"

class Bases {
public:
    Bases();

    void clearBases();
    void move(teamPtr &attackingTeam);
    void setHomePlayer(playerPtr player);
private:
    std::vector<playerPtr> m_bases = {};
    bool isPlayerHome() const;
};

#endif //BASEBALL_CPLUS_BASE_H
