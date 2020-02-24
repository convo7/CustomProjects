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
    explicit Base(basePtr nextBase) : m_next(nextBase) {};

    bool setPlayer(playerPtr player);
    void setNextBase(basePtr &next);
    bool hasPlayer();
    void move();

    playerPtr m_player = {};
    basePtr m_next = {};
};

#endif //BASEBALL_CPLUS_BASE_H
