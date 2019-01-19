#pragma once
#include "Command.h"
class LoadGameCommand :
	public Command
{
public:
	LoadGameCommand(std::string title);
	~LoadGameCommand();

	virtual void execute() override;
};

