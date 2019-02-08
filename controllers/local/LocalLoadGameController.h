#pragma once
#include "LoadGameController.h"
#include "LocalOperationController.h"

class LocalLoadGameController
  : public LoadGameController, public LocalOperationController
{
public:
  LocalLoadGameController();
  ~LocalLoadGameController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
  virtual void load() override;

};
