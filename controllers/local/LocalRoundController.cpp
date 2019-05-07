#include "LocalRoundController.h"
#include "Result.h"
#include <iostream>

using namespace std;

LocalRoundController::LocalRoundController(Session* gsessioname)
	: Controller(session)
{
}

LocalRoundController::~LocalRoundController()
{
}

void LocalRoundController::addRound(Combination* playerCombination)
{
  Result* result = new Result(session_->getSecretCombination(), playerCombination);
  std::pair<Combination*, Result*> round(move(playerCombination), move(result));
  session_->addRound(move(round));
  session_->nextState();
}

bool LocalRoundController::isGameFinished() {
	return session_->isGameFinished();
}
