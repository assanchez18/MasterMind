#pragma once
#include "InGameController.h"

class InGameView {
public:
  InGameView();
  ~InGameView();
 
  void interact(InGameController* controller);
};

