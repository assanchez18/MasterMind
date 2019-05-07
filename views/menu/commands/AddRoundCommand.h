#pragma once
#include "InGameCommand.h"

class AddRoundCommand
  : public InGameCommand {
public:
  AddRoundCommand(std::string title, InGameController* controller);
  ~AddRoundCommand();

  void execute();
  virtual bool isActive() override;
};