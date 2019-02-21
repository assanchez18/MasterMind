#pragma once
#include <string>

class SaveGameView {
public:
  SaveGameView();
  ~SaveGameView();

  std::string requestGameName();
  bool askIfOverride();

private:
  void printOptions();
};

