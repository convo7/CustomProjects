#ifndef BASEBALL_PITCHING_H
#define BASEBALL_PITCHING_H

#include <vector>

class Pitching {
public:
    int pitch();
private:
    std::vector<int> m_pitch = {200,150};
};


#endif //BASEBALL_PITCHING_H
