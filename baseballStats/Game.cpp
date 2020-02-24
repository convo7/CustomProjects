#include "Game.h"
#include "Team.h"

Game::Game(teamPtr team1, teamPtr team2) : m_team1(std::move(team1)), m_team2(std::move(team2)) {
    m_bases = std::make_shared<Bases>();
}

void Game::start() {
    while (m_team1->getScore() == m_team2->getScore() || m_inning <= 9) {
        m_inning++;
        attack(m_team2, m_team1);
        attack(m_team1, m_team2);
    }
}

void Game::attack(teamPtr &attackTeam, teamPtr &defenceTeam) {
    while (m_outs < 3) {

        int strikes = 0;
        int balls = 0;

        m_bases->setHomePlayer(attackTeam->getBatter());

        auto random = defenceTeam->getRandom();
        if (random->randomHit(defenceTeam->getPitcher()->pitch(),
                              attackTeam->getBatter()->batting.m_contact)) {
            m_bases->move(attackTeam);
        }
        else
        {
        m_outs++;
        }
    }
    m_bases->clearBases();
    m_outs = 0;
}

void Game::result() {
    std::cout << "Team " << m_team1->getName() << " -> " << m_team1->getScore();
    std::cout << std::endl;
    std::cout << "Team " << m_team2->getName() << " -> " << m_team2->getScore();
}