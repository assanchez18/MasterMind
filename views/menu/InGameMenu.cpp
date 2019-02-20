#include "InGameMenu.h"
#include "AddRoundCommand.h"
#include "SaveGameCommand.h"
#include "ExitCommand.h"

InGameMenu::InGameMenu(InGameController* controller) {
  commandList_.emplace_back(new AddRoundCommand("Añadir nueva combinación.", controller));
  commandList_.emplace_back(new SaveGameCommand("Cargar partida guardada.", controller));
  //commandList_.emplace_back(new CloseGameCommand("Cargar partida guardada.", controller));
  //TO-DO: Refactor exit command
  commandList_.emplace_back(new ExitCommand("Salir de la partida.", controller->getExitController()));
}


InGameMenu::~InGameMenu() {
}
