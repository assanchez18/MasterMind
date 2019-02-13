#pragma once
#include "OutGameCommand.h"

class ExitCommand :
  public OutGameCommand {
public:
  ExitCommand(std::string title, OutGameController* controller);
  ~ExitCommand();

  virtual void execute() override;
};

