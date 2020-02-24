#ifndef BASEBALL_CPLUS_TEAM_H
#define BASEBALL_CPLUS_TEAM_H

#include "Player.h"
#include "IRandomize.h"
#include "Types.h"

#include <string>


class Team {
public:
    explicit Team(std::string teamName, randomizePtr random);

    playerPtr getBatter();
    int getScore() const;
    void score(int var);
    pitcherPtr getPitcher() const;
    std::string getName() const;
    randomizePtr getRandom() const;

private:
    std::string m_name = {};
    pitcherPtr m_pitcher = {};
    std::vector<playerPtr> m_fielders = {};
    std::vector<playerPtr> m_batters_list = {};

    randomizePtr m_random = {};

    int m_betterCount = 0;
    int m_score = 0;
};

#endif //BASEBALL_CPLUS_TEAM_H
