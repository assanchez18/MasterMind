#pragma once

#include "MasterMind.h"

class Command {
public:
	Command(std::string title) :
		title(title)
	{}

	virtual void execute() = 0;
	inline const std::string getTitle() { return title; }
protected:
	const std::string title;
};