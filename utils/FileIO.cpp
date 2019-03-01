#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include <assert.h>

FileIO::FileIO() {
}


FileIO::~FileIO() {
}

void FileIO::saveGame(MasterMind * game, string name) {
  assert(game != nullptr);
  ofstream myFile;
  myFile.open(name);
  myFile << "Name: " << name << "\n";
  myFile << "Secret combination: " << game->getSecretCombination()->toString() << "\n";
  myFile << "Number of rounds: " << game->getPlayedRounds() << "\n";
  for (int i = 0; i < game->getPlayedRounds(); i++) {
    myFile << "Round " << i << ": " << game->getRounds().at(i).first->toString() 
           << "*" << game->getRounds().at(i).second->toString();
  }
  myFile.close();
}

int FileIO::readConfig(string fileName, const char splitter, map<string, string> &config) {
  map<string, string> configuration;
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "Unable to open config file " << fileName << endl;
    return -1;
  }
  string line;
  size_t pos;
  string key;
  string value;
  while (getline(file, line)) {
    pos = line.find(splitter);
    key = line.substr(0, pos);
    value = line.substr(pos + 1, line.size());
    //    if (config.count(key) > 0) {
      //    cout << "Duplicated config attribute " << key << endl;
        //  return -1;
        //}
    config.insert_or_assign(key, value);
  }
  return 0;
}


