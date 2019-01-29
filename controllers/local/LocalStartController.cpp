#include "LocalStartController.h"
namespace controllers {
namespace locals {

LocalStartController::LocalStartController(MasterMind * game)
  : LocalOperationController(game)
{
}

LocalStartController::~LocalStartController()
{
}

void LocalStartController::accept(IOperationControllerVisitor * operationControllerVisitor)
{
  operationControllerVisitor->visit(this);
}

void LocalStartController::start()
{
  game->startGame();
}

int LocalStartController::getNumberOfRounds()
{
  return game->getNumberOfRounds();
}
}
}