#pragma once
#include "LocalOperationController.h"
#include "OutGameController.h"
#include "StartController.h"
#include "LoadGameCommand.h"

class LoadGameController;
class LocalOutGameController
  : public OutGameController, public LocalOperationController, Controller {
public:
  LocalOutGameController(MasterMind* game);
  ~LocalOutGameController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
  
  virtual void startGame() override;
  virtual void loadGame() override;
  virtual void exitGame() override;

};
