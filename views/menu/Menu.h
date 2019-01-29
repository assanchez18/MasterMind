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
	Command* getCommand(int position);
	void execute(int command);
protected:
	std::vector<Command*> commandList;
	ExitCommand* exitCommand;
	virtual void createExitCommand();
	virtual void setGame(models::MasterMind* game);
};

