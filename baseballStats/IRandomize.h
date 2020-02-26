#ifndef BASEBALL_IRANDOMIZE_H
#define BASEBALL_IRANDOMIZE_H

#include <random>
#include <ctime>

class IRandomize
{
public:
    virtual int randomStat(int lower, int higher) = 0;
    virtual bool randomHit(int pitch, int contact) = 0;
  //virtual bool randomThrow(int accuracity) = 0;
};

#endif //BASEBALL_IRANDOMIZE_H
