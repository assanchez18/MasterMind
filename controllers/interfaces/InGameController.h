#pragma once
#include "RoundController.h"
#include "BoardController.h"
#include "ExitController.h"
#include "Combination.h"

class InGameController {
public:
  virtual void addRound(Combination* combination) = 0;
  virtual void saveGame() = 0;
  virtual void closeGame() = 0;
  virtual void exitGame() = 0;
  virtual BoardController* getBoardController() = 0;
  virtual ExitController* getExitController() = 0;

protected:
  RoundController* roundController_;
  BoardController* boardController_;
  //SaveGameController* saveController_;
  //CloseGameController* closeCotroller_;
  ExitController* exitController_;
};