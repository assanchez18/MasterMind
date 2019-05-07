#pragma once
#include "InGameCommand.h"
class UndoCommand :
	public InGameCommand
{
public:
	UndoCommand(std::string title, InGameController* controller);
	~UndoCommand();

	// Heredado v�a InGameCommand
	virtual void execute() override;
	virtual bool isActive() override;
};

