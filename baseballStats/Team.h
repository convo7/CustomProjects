#ifndef BASEBALL_CPLUS_TEAM_H
#define BASEBALL_CPLUS_TEAM_H

#include "Player.h"

#include <string>

class Team {
public:
    explicit Team(std::string teamName);

    playerPtr getBatter();
    int getScore() const;
    void score(int var);
    pitcherPtr getPitcher() const;
    std::string getName() const;

private:
    std::string m_name = {};
    pitcherPtr m_pitcher = {};
    std::vector<playerPtr> m_fielders = {};
    std::vector<playerPtr> m_batters_list = {};

    // pointer to IRandomise;

    int m_betterCount = 0;
    int m_score = 0;
};

#endif //BASEBALL_CPLUS_TEAM_H
