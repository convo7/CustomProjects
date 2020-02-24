#ifndef BASEBALL_CPLUS_BASE_H
#define BASEBALL_CPLUS_BASE_H

#include "Player.h"
#include "Team.h"

class Bases;
class Player;
class Team;

typedef std::shared_ptr<Player> playerPtr;
typedef std::shared_ptr<Bases> basePtr;
typedef std::shared_ptr<Team> teamPtr;

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
