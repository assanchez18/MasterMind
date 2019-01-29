#pragma once
#include "Command.h"
class StartGameCommand :
	public Command
{
public:
	StartGameCommand(std::string title);
	~StartGameCommand();

	virtual void execute() override;
};

