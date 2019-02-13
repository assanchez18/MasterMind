#pragma once
#include "ExitController.h"
#include "Controller.h"

class LocalExitController :
  public ExitController, Controller {
public:
  LocalExitController(MasterMind* game);
  ~LocalExitController();

  virtual void exitGame() override;
};

