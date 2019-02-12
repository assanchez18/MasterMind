#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
	delete exitCommand_;
}


void Menu::createExitCommand()
{
	exitCommand_ = new ExitCommand("Salir de MasterMind.");
	commandList_.emplace_back(exitCommand_);
}

std::vector<Command*> Menu::getCommandList()
{
	return commandList_;
}

