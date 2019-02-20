#pragma once
#include <string>

class SaveGameController {
public:
  virtual void saveGame(std::string gameName) = 0;
};