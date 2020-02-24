#ifndef BASEBALL_TYPES_H
#define BASEBALL_TYPES_H

#include <iostream>
#include <memory>

class Team;
class Player;
class Pitcher;
class Bases;
class IRandomize;


typedef std::shared_ptr<Team> teamPtr;
typedef std::shared_ptr<Player> playerPtr;
typedef std::shared_ptr<Pitcher> pitcherPtr;
typedef std::shared_ptr<Bases> basePtr;
typedef std::shared_ptr<IRandomize> randomizePtr;

#endif //BASEBALL_TYPES_H
