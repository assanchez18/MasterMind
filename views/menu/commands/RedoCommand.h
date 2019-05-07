#pragma once
#include "InGameCommand.h"
class RedoCommand :
	public InGameCommand
{
public:
	RedoCommand(std::string title, InGameController* controller);
	~RedoCommand();

	// Heredado v�a InGameCommand
	virtual void execute() override;
	virtual bool isActive() override;
};

