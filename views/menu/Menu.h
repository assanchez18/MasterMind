#pragma once
#include "Command.h"
#include "ExitCommand.h"
#include <vector>

class Menu
{
public:
  Menu();
  ~Menu();

  //QUITAR ESTE PRINT Y METERLO EN UN MenuView
  void print();

  std::vector<Command*>& getCommands();
  Command* selectOption();

protected:
	std::vector<Command*> commandList;
	ExitCommand* exitCommand;
	virtual void createExitCommand();
	virtual void setGame(MasterMind* game);
};

