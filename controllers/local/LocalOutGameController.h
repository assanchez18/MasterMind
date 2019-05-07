#pragma once
#include "LocalOperationController.h"
#include "OutGameController.h"
#include "Controller.h"

class LocalOutGameController
  : public OutGameController, public LocalOperationController, Controller {
public:
  LocalOutGameController(Session* game);
  ~LocalOutGameController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
  
  virtual void startGame() override;
  virtual void loadGame(std::string gameName) override;
  virtual void exitGame() override;
};
