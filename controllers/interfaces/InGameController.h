#pragma once
#include "RoundController.h"
#include "ExitController.h"
#include "Combination.h"

class InGameController {
public:
  virtual void addRound(Combination* combination) = 0;
  virtual void saveGame() = 0;
  virtual void closeGame() = 0;
  virtual void exitGame() = 0;

protected:
  RoundController* roundController_;
  //SaveGameController* saveController_;
  //CloseGameController* closeCotroller_;
  ExitController* exitController_;
};