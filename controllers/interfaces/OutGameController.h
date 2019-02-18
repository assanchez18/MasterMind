#pragma once
#include "StartController.h"
#include "LoadGameController.h"
#include "ExitController.h"

class OutGameController {
public:
  virtual void startGame() = 0;
  virtual void loadGame() = 0;
  virtual void exitGame() = 0;
  virtual ExitController* getExitController() = 0;

protected:
  StartController* startController_;
  LoadGameController* loadController_;
  ExitController* exitController_;
};