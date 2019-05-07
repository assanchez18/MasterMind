#pragma once
#include "Controller.h"
#include "StartController.h"
#include "LoadGameController.h"
#include "ExitController.h"

class OutGameController 
 : public Controller {
public:
  virtual void startGame() = 0;
  virtual void loadGame(std::string gameName) = 0;
  virtual void exitGame() = 0;

protected:
  StartController* startController_;
  LoadGameController* loadController_;
  ExitController* exitController_;
};