#include "OutGameMenu.h"
#include "StartGameCommand.h"
#include "LoadGameCommand.h"

OutGameMenu::OutGameMenu() {
  commandList.emplace_back(new StartGameCommand("Empezar nueva partida."));
  commandList.emplace_back(new LoadGameCommand("Cargar partida guardada."));
  createExitCommand();
}


OutGameMenu::~OutGameMenu() {
}
