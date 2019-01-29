// MasterMind.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
#include "Logic.h"
#include "MasterMindView.h"

using namespace controllers;
int main()
{
	Logic logic = Logic::Logic();
	MasterMindView view = MasterMindView::MasterMindView();
	do {
		IOperationController* controller = logic.getController();
		view.interact(controller);
	} while (!logic.isEnd());
	std::cout << "THE END!!";
}

// TODO:	Clase turno --> Libera a MasterMind de funcionalidad.
//			Patrón State en la factoría de controllers --> eliminamos switch enorme.
//			Convertir result en un tipo de combinación.