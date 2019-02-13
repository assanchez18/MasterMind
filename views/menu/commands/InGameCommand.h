#pragma once
#include "Command.h"
#include "InGameController.h"

class InGameCommand :
  public Command {
public:
  InGameCommand(std::string title, InGameController* controller);
  ~InGameCommand();

protected:
  InGameController* controller_;
};

