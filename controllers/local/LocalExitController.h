#pragma once
#include "ExitController.h"
#include "Controller.h"

class LocalExitController :
  public ExitController, Controller {
public:
  LocalExitController(Session* session);
  ~LocalExitController();

  virtual void exitGame() override;
};

