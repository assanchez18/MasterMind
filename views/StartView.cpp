#include "StartView.h"
#include <iostream>
using namespace std;

StartView::StartView() {
}


StartView::~StartView() {
}

void StartView::interact(OutGameController * startController) {
	cout << "El juego est� a punto de comenzar!\n" <<
		"Tienes " << startController->getNumberOfRounds() << " para adivinar la combinaci�n secreta." << endl;
}

