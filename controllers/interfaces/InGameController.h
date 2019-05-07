#pragma once
#include "Controller.h"
#include "RoundController.h"
#include "SaveGameController.h"
#include "ExitController.h"
#include "RedoController.h"
#include "UndoController.h"

class InGameController 
	: public Controller {
public:
  virtual void addRound(Combination* combination) = 0;
  virtual bool isGameFinished() = 0;
  virtual bool redoable() = 0;
  virtual bool undoable() = 0;
  virtual void saveGame(std::string gameName) = 0;
  virtual void closeGame() = 0;
  virtual void exitGame() = 0;
  
protected:
	RoundController* roundController_;
	SaveGameController* saveController_;
	ExitController* exitController_;
	RedoController* redoController_;
	UndoController* undoController_;
};