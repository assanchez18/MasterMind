#pragma once
#include "OutGameController.h"

class OutGameView
{
public:
	OutGameView();
	~OutGameView();

	void interact(OutGameController* controller);
};

