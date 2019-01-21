#pragma once
#include "Command.h"
class ExitCommand :
	public Command
{
public:
	ExitCommand(std::string title);
	~ExitCommand();

	// Heredado vía Command
	virtual void execute() override;
};

