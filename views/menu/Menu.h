#pragma once
#include "Command.h"
#include "ExitCommand.h"
#include <vector>

class Menu
{
public:
  Menu();
  ~Menu();

  std::vector<Command*> getCommandList();

protected:
	std::vector<Command*> commandList_;
};

