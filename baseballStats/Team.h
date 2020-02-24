#ifndef BASEBALL_CPLUS_TEAM_H
#define BASEBALL_CPLUS_TEAM_H

#include "Player.h"

#include <string>

class Team {
public:
    explicit Team(std::string teamName) : m_name(std::move(teamName)) {
        m_pitcher = std::make_shared<Pitcher>();
        while (m_fielders.size() < 9) {
            auto player = std::make_shared<Player>();
            m_fielders.push_back(player);
            m_batters_list.push_back(player);
        }
        m_batters_list.push_back(m_pitcher);
    };

    playerPtr getBatter() {
        if (m_betterCount > 8) {
            m_betterCount = 0;
            return m_batters_list.at(0);
        }
        return m_batters_list.at(m_betterCount);
    }

    int getScore() const {
        return m_score;
    }

    void score(int var) {
        m_score += var;
    }

    pitcherPtr getPitcher() const {
        return m_pitcher;
    }

    std::string getName() const {
        return m_name;
    }

private:
    std::string m_name = {};
    pitcherPtr m_pitcher = {};
    std::vector<playerPtr> m_fielders = {};
    std::vector<playerPtr> m_batters_list = {};

    int m_betterCount = 0;
    int m_score = 0;
};

#endif //BASEBALL_CPLUS_TEAM_H
