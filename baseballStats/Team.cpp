#include "Team.h"

Team::Team(std::string teamName) : m_name(std::move(teamName)) {
    m_pitcher = std::make_shared<Pitcher>();
    while (m_fielders.size() < 9) {
        auto player = std::make_shared<Player>();
        m_fielders.push_back(player);
        m_batters_list.push_back(player);
    }
    m_batters_list.push_back(m_pitcher);
};

playerPtr Team::getBatter() {
    if (m_betterCount > 8) {
        m_betterCount = 0;
        return m_batters_list.at(0);
    }
    return m_batters_list.at(m_betterCount);
}

int Team::getScore() const {
    return m_score;
}

void Team::score(int var) {
    m_score += var;
}

pitcherPtr Team::getPitcher() const {
    return m_pitcher;
}

std::string Team::getName() const {
    return m_name;
}