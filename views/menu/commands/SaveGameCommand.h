#pragma once
#include <string>
#include "InGameController.h"
#include "InGameCommand.h"

class SaveGameCommand
  : public InGameCommand {
public:
  SaveGameCommand(std::string title, InGameController* controller);
  ~SaveGameCommand();

  // Inherited via InGameCommand
  virtual void execute() override;
};

