#pragma once
#include "Menu.h"
#include "OutGameController.h"

class OutGameMenu :
  public Menu {
public:
  OutGameMenu(OutGameController* controller);
  ~OutGameMenu();
};

