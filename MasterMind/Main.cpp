// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Logic.h"
#include "IView.h"

int main()
{
	Logic logic = Logic::Logic();

	

	do {
		IController* controller = logic.getController();
		IView view = interact(controller);
		//c->action();
		logic.changeState();
	} while (!logic.isEnd());
	std::cout << "THE END!!";
}

// TODO:	Clase turno --> Libera a MasterMind de funcionalidad.
//			Patrón State en la factoría de controllers --> eliminamos switch enorme.
//			Convertir result en un tipo de combinación.




