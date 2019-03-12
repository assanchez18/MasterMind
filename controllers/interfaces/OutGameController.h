#pragma once
#include "StartController.h"
#include "LoadGameController.h"
#include "ExitController.h"
#include "BoardController.h"

class OutGameController {
public:
  virtual void startGame() = 0;
  virtual void loadGame(std::string gameName) = 0;
  virtual void exitGame() = 0;
  virtual ExitController* getExitController() = 0;
  virtual BoardController* getBoardController() = 0;

protected:
  StartController* startController_;
  LoadGameController* loadController_;
  BoardController* boardController_;
  ExitController* exitController_;
};