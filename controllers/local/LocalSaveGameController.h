#pragma once
#include "SaveGameController.h"
#include "Controller.h"

class LocalSaveGameController 
: public SaveGameController, Controller{
public:
  LocalSaveGameController(Session * session);
  ~LocalSaveGameController();

  virtual void saveGame(std::string gameName) override;
};

