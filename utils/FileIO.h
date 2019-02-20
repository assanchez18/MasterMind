#pragma once

#include <string>
#include <map>
#include "MasterMind.h"

class FileIO {
public:
  FileIO();
  ~FileIO();

  void saveGame(MasterMind* game, string name);
  int readConfig(string fileName, const char splitter, map<string, string> &config);
};

