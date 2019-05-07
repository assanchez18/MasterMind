#pragma once
#include "LoadGameController.h"
#include "Controller.h"

class LocalLoadGameController :
  public LoadGameController, Controller {
public:
  LocalLoadGameController(Session* session);
  ~LocalLoadGameController();

  virtual void loadGame(std::string gameName) override;
};

