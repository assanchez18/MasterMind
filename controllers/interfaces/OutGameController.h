#pragma once
#include "StartController.h"
#include "LoadGameController.h"

class OutGameController {
public:
  virtual void startGame() = 0;
  virtual void loadGame() = 0;

protected:
  StartController* startController_;
  LoadGameController* loadController_;

};