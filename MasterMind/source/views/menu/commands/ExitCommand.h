#pragma once
#include "Command.h"
class ExitCommand :
	public Command
{
public:
	ExitCommand(std::string title);
	~ExitCommand();

	// Heredado v�a Command
	virtual void execute() override;
};

