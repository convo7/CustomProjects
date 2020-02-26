#include "Player.h"

#include <random>

int Pitcher::pitch() {
    srand(time(0));
    auto tmp = rand() % (m_pitch.size() - 1) + 0;
    return m_pitch.at(tmp)--;
}
