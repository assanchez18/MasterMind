#pragma once
#include "InGameController.h"
#include "Controller.h"
#include "LocalOperationController.h"

class LocalInGameController :
  public InGameController, public LocalOperationController, Controller {
public:
  LocalInGameController(MasterMind* game);
  ~LocalInGameController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;

  virtual void addRound(Combination* combination) override;
  virtual void saveGame() override;
  virtual void closeGame() override;
  virtual void exitGame() override;
  virtual BoardController* getBoardController() override;
};

