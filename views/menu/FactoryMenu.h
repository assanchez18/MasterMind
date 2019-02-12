#pragma once
#include "Menu.h"

#include "OutGameMenu.h"

class FactoryMenu {

public:
	static Menu* createMenu(OutGameController* controller) {
		return new OutGameMenu(controller);
	}
};