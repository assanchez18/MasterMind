#include "pch.h"
#include "StartView.h"
#include <iostream>
using namespace std;

StartView::StartView()
{
}


StartView::~StartView()
{
}

void StartView::interact(StartController * startController)
{
	startController->start();
	cout << "El juego está a punto de comenzar!\n" <<
		"Tienes 12 "/*<< startController->getNumberOfRounds() << */ << " para adivinar la combinación secreta." << endl;
}

