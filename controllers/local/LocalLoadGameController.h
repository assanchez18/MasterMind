#pragma once
#include "LoadGameController.h"
#include "Controller.h"
class LocalLoadGameController :
  public LoadGameController, Controller {
public:
  LocalLoadGameController(MasterMind* game);
  ~LocalLoadGameController();

  virtual void loadGame() override;
};

