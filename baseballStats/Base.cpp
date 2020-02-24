#include "Base.h"

bool Base::setPlayer(playerPtr player) {
    m_player = player;
    return true;
}

void Base::setNextBase(basePtr &next) {
    m_next = next;
}

bool Base::hasPlayer() { return m_player != nullptr; }

void Base::move() {
    if (m_next->hasPlayer()) {
        m_next->move();
        m_next->setPlayer(m_player);
    } else {
        m_next->setPlayer(m_player);
        m_player.reset();
        m_player = nullptr;
    }
}