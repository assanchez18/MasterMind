#pragma once
#include "Menu.h"
#include "InGameController.h"

class InGameMenu :
  public Menu {
public:
  InGameMenu(InGameController* controller);
  ~InGameMenu();
};

