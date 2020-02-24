#include "Player.h"
#include "Team.h"
#include "Game.h"
#include "StdRandomize.h"

int main() {

    std::shared_ptr<IRandomize> random = std::make_shared<StdRandomize>();

    auto team1 = std::make_shared<Team>("Rodgers", random);
    auto team2 = std::make_shared<Team>("Pirates", random);

    Game game(team1, team2);
    game.start();
    game.result();

    return 0;
}
