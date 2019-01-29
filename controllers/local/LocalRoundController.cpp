#include "LocalRoundController.h"
#include <iostream>

using namespace std;
namespace controllers {
namespace locals {

LocalRoundController::LocalRoundController(MasterMind* game)
  : LocalOperationController(game)
{
}

LocalRoundController::~LocalRoundController()
{
}

void LocalRoundController::addRound(Combination* playerCombination)
{
  Round* round = new Round(playerCombination);
  round->checkResult(game->getSecretCombination());
  game->addRound(std::move(round));
  game->setState(GameState::CHECK_RESULT);
}

void LocalRoundController::accept(IOperationControllerVisitor * operationControllerVisitor)
{
  operationControllerVisitor->visit(this);
}
}
}