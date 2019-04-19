#include "InGameMenu.h"
#include "AddRoundCommand.h"
#include "SaveGameCommand.h"
#include "ExitCommand.h"

InGameMenu::InGameMenu(InGameController* controller) {
  commandList_.emplace_back(new AddRoundCommand("A�adir nueva combinaci�n.", controller));
  commandList_.emplace_back(new SaveGameCommand("Guardar partida.", controller));
  //TO-DO: Refactor exit command
  commandList_.emplace_back(new ExitCommand("Salir de la partida.", controller->getExitController()));
}


InGameMenu::~InGameMenu() {
}
