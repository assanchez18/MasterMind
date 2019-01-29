#pragma once
#include "RoundController.h"
#include "LocalOperationController.h"
namespace controllers {
namespace locals {
class LocalRoundController
  : public RoundController, public LocalOperationController
{
public:
  LocalRoundController(MasterMind* game);
  ~LocalRoundController();

  virtual void addRound(Combination* playerCombination) override;
  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
};

}
}