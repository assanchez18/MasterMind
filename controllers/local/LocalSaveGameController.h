#pragma once
#include "SaveGameController.h"
#include "Controller.h"

class LocalSaveGameController 
: public SaveGameController, Controller{
public:
  LocalSaveGameController(MasterMind * game);
  ~LocalSaveGameController();

  virtual void saveGame(std::string gameName) override;
};

