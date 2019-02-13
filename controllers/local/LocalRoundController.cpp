#include "LocalRoundController.h"
#include "Result.h"
#include <iostream>

using namespace std;

LocalRoundController::LocalRoundController(MasterMind* game)
	: Controller(game)
{
}

LocalRoundController::~LocalRoundController()
{
}

void LocalRoundController::addRound(Combination* playerCombination)
{
  Result* result = new Result(game_->getSecretCombination(), playerCombination);
  std::pair<Combination*, Result*> round(move(playerCombination), move(result));
  game_->addRound(move(round));
  if (result->isSolution()) {
  }
  //TO-DO: verify if game is finished or max rounds quizás desde el comando.
}
