#pragma once
#include <vector>

class Command;
class MenuController
{
public:
	virtual void createMenu() = 0;
	virtual std::vector<Command*> getCommands() = 0;
	virtual void execute(int command) = 0;
};

