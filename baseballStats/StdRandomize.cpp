#include "StdRandomize.h"

int StdRandomize::randomStat(int lower, int higher) {
    if (lower > higher)
        return 60;

    srand(time(nullptr));
    auto result = rand() % higher + lower;
    return result;
}

bool StdRandomize::randomHit(int pitch, int contact) {
    if (pitch <= contact)
        return false;
    auto result = rand() % pitch + 1;
    return result < contact;
}
