#pragma once
#include "InGameController.h"
#include "LocalOperationController.h"

class LocalInGameController :
  public InGameController, public LocalOperationController, Controller {
public:
  LocalInGameController(Session* game);
  ~LocalInGameController();

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;

  virtual void addRound(Combination* combination) override;
  virtual bool isGameFinished() override;

  virtual void saveGame(std::string gameName) override;
  virtual void closeGame() override;
  virtual void exitGame() override;

  // Heredado vía InGameController
  virtual bool redoable() override;
  virtual bool undoable() override;

};

