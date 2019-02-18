#pragma once
#include "Command.h"
#include "ExitController.h"

class ExitCommand :
  public Command {
public:
  ExitCommand(std::string title, ExitController* controller);
  ~ExitCommand();

  void execute();

private:
  ExitController* controller_;
};

