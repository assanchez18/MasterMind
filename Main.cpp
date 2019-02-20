// MasterMind.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>

#include "Logic.h"
#include "MasterMindView.h"
#include "Main.h"

#include "FileIO.h"
#include "Config.h"
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  loadGame(argv[1]);

	Logic logic = Logic::Logic();
	MasterMindView view = MasterMindView::MasterMindView();
	do {
		IOperationController* controller = logic.getController();
		view.interact(controller);
	} while (!logic.isEnd());
	std::cout << "THE END!!";
}

void loadGame(char* param) {
  Config* config = Config::getInstance();
  config->setConfigFile(param);
  config->loadConfig();
}

// TODO:	Clase turno --> Libera a MasterMind de funcionalidad.
//			Patrón State en la factoría de controllers --> eliminamos switch enorme.
//			Convertir result en un tipo de combinación.