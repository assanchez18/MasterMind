#pragma once

#include "MasterMind.h"

class Command {
public:
	Command(std::string title) :
		title(title),
		game(nullptr)
	{}

	virtual void execute() = 0;
	inline const std::string getTitle() { return title; }
	inline void setGame(MasterMind* game) { this->game = game; }
protected:
	MasterMind* game;
	const std::string title;
};