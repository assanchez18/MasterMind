#pragma once
#include <string>
#include "InGameController.h"
#include "InGameCommand.h"

class SaveGameCommand
  : public InGameCommand {
public:
  SaveGameCommand(std::string title, InGameController* controller);
  ~SaveGameCommand();

  virtual void execute() override;
  virtual bool isActive() override;
private:
  int checkIfFileExists(const std::string &gameName);
};

