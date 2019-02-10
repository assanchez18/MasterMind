#include "InitialMenu.h"
#include "StartGameCommand.h"
#include "LoadGameCommand.h"

InitialMenu::InitialMenu()
{
	commandList.emplace_back(new StartGameCommand("Empezar nueva partida."));
	commandList.emplace_back(new LoadGameCommand("Cargar partida guardada."));
	createExitCommand();
}


InitialMenu::~InitialMenu()
{
}
