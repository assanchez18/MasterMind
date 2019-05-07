#pragma once

#include <string>
#include <map>
#include "Session.h"
#include <fstream>

class FileIO {
public:
  FileIO();
  ~FileIO();

  void saveGame(MasterMind* game, string name);
  int readConfig(string fileName, const char splitter, map<string, string> &config);
  void loadGame(string name, Session* session);

private:
  string getNextValue(string line);
};

