#ifndef BASEBALL_STDRANDOMIZE_H
#define BASEBALL_STDRANDOMIZE_H

#include "IRandomize.h"

class StdRandomize : public IRandomize {
public:
     int randomStat(int lower, int higher) override ;
     bool randomHit(int pitch, int contact) override ;
};


#endif //BASEBALL_STDRANDOMIZE_H
