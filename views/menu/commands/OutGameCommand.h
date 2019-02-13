#pragma once
#include "OutGameController.h"
#include "Command.h"

class OutGameCommand :
  public Command {
public:
  OutGameCommand(std::string title, OutGameController* controller);
  ~OutGameCommand();

protected:
  OutGameController* controller_;
};