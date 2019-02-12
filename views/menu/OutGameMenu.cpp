#include "OutGameMenu.h"
#include "StartGameCommand.h"
#include "LoadGameCommand.h"

OutGameMenu::OutGameMenu(OutGameController* controller) {
  commandList_.emplace_back(new StartGameCommand("Empezar nueva partida.", controller));
  commandList_.emplace_back(new LoadGameCommand("Cargar partida guardada.", controller));
  createExitCommand();
}


OutGameMenu::~OutGameMenu() {
}

