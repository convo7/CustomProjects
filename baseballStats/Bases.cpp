#include "Bases.h"

Bases::Bases() {
    m_bases.reserve(4);
    clearBases();
}

bool Bases::isPlayerHome() const {
    return !(m_bases.at(3) == nullptr);
}

void Bases::move(teamPtr &attackingTeam) {

    int base = 2;
    while (base >= 0) {
        if (m_bases.at(base)) {
            m_bases.at(base + 1) = m_bases.at(base);
            m_bases.at(base) = nullptr;
        }
        base--;
    }

    if (isPlayerHome())
        attackingTeam->score(1);
}

void Bases::setHomePlayer(playerPtr player) {
    m_bases.at(0) = player;
}

void Bases::clearBases() {
    for (int i = 0; i < 4; i++)
        m_bases.push_back(nullptr);
}




