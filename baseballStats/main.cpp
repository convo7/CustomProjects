#include "Player.h"
#include "Team.h"
#include "Game.h"

int main() {

    auto team1 = std::make_shared<Team>("Rodgers");
    auto team2 = std::make_shared<Team>("Pirates");

    Game game(team1, team2);
    game.start();
    game.result();

    return 0;
}
