#include "Game.h"
#include "Team.h"

Game::Game(teamPtr team1, teamPtr team2) : m_team1(std::move(team1)), m_team2(std::move(team2)) {
    m_base_home = std::make_shared<Base>();
    m_base3 = std::make_shared<Base>(m_base_home);
    m_base2 = std::make_shared<Base>(m_base3);
    m_base1 = std::make_shared<Base>(m_base2);
    m_base_home->setNextBase(m_base1);
}

void Game::start() {
    while (m_team1->getScore() == m_team2->getScore() || m_inning <= 9) {
        m_inning++;
        attack(m_team1, m_team2);
        attack(m_team2, m_team1);
    }
}

bool Game::probabilityResult(int var, int &againts) {
    int result = 1 - rand() & 110;
    return result <= 25;
}

void Game::attack(teamPtr &attackTeam, teamPtr &defenceTeam) {

    while (m_outs < 3) {

        int strikes = 0;
        int balls = 0;

        m_base_home->setPlayer(attackTeam->getBatter());
        if (probabilityResult(defenceTeam->getPitcher()->throwPitch(),
                              attackTeam->getBatter()->batting.m_contact)) {
            m_base_home->move();
            if (m_base_home->hasPlayer()) attackTeam->score(1);
        } else { m_outs++; }
    }
}

void Game::result() {
    std::cout << "Team " << m_team1->getName() << " -> " << m_team1->getScore();
    std::cout << std::endl;
    std::cout << "Team " << m_team2->getName() << " -> " << m_team2->getScore();
}