#include "pch.h"
#include "StartControllerView.h"
#include <iostream>
using namespace std;

StartControllerView::StartControllerView()
{
}


StartControllerView::~StartControllerView()
{
}

void StartControllerView::interact(StartController * startController)
{
	startController->start();
	cout << "El juego está a punto de comenzar!\n" <<
		"Tienes 12 "/*<< startController->getNumberOfRounds() << */ << " para adivinar la combinación secreta." << endl;
}

