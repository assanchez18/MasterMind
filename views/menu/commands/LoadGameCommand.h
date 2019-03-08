#pragma once
#include "OutGameCommand.h"

class LoadGameCommand :
  public OutGameCommand {
public:
  LoadGameCommand(std::string title, OutGameController* controller);
  ~LoadGameCommand();

  void execute();
private:
  std::string selectFileToLoad();
  int askForOption(int maxOption);
};

