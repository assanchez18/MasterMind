#pragma once
#include "StartController.h"
#include "MasterMind.h"
#include "LocalOperationController.h"
namespace controllers {
namespace locals {
class LocalStartController
  : public StartController, public LocalOperationController
{
public:
  LocalStartController(MasterMind* game);
  ~LocalStartController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
  virtual void start() override;
  virtual int getNumberOfRounds() override;
};
}
}
