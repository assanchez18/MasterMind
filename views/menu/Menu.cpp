#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
	delete exitCommand;
}



void Menu::setGame(MasterMind* game)
{
	for (Command* c : commandList) 
	{
		c->setGame(game);
	}
}

void Menu::createExitCommand()
{
	exitCommand = new ExitCommand("Salir de MasterMind.");
	commandList.emplace_back(exitCommand);
}

std::vector<Command*>& Menu::getCommands()
{
	return commandList;
}

