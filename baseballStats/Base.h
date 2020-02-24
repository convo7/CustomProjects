#ifndef BASEBALL_CPLUS_BASE_H
#define BASEBALL_CPLUS_BASE_H

#include "Player.h"

class Base;
class Player;
typedef std::shared_ptr<Player> playerPtr;
typedef std::shared_ptr<Base> basePtr;

class Base {
public:
    Base() = default;

    explicit Base(basePtr nextBase) : m_next(nextBase) {
    }

    bool setPlayer(playerPtr player) {
        m_player = player;
        return true;
    }

    void setNextBase(basePtr &next) {
        m_next = next;
    }

    bool hasPlayer() { return m_player != nullptr; }

    void move() {
        if (m_next->hasPlayer()) {
            m_next->move();
            m_next->setPlayer(m_player);
        } else {
            m_next->setPlayer(m_player);
            m_player.reset();
            m_player = nullptr;
        }
    }

    playerPtr m_player = {};
    basePtr m_next = {};

};

#endif //BASEBALL_CPLUS_BASE_H
