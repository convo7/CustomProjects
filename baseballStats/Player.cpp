#include "Player.h"

int Pitcher::throwPitch() {
    m_fastball--;
    auto result = m_fastball - 10 - rand() % m_fastball;
    return result;
}