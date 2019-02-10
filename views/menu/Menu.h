#pragma once
#include "Command.h"
#include "ExitCommand.h"
#include <vector>

class Menu
{
public:
  Menu();
  ~Menu();

  std::vector<Command*>& getCommands();


protected:
	std::vector<Command*> commandList;
	ExitCommand* exitCommand;
	virtual void createExitCommand();
};

