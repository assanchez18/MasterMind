#pragma once
#include "Menu.h"
#include "OutGameMenu.h"
#include "InGameMenu.h"

class FactoryMenu {

public:
  static Menu* createMenu(OutGameController* controller) {
    return new OutGameMenu(controller);
  }

  static Menu* createMenu(InGameController* controller) {
    return new InGameMenu(controller);
  }
};