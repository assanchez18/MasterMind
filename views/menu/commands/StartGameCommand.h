#pragma once
#include "OutGameCommand.h"
#include "Command.h"
class StartGameCommand :
	public OutGameCommand
{
public:
	StartGameCommand(std::string title, OutGameController* controller);
	~StartGameCommand();

	void execute();

};

