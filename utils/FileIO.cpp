#include "FileIO.h"
#include <iostream>
#include <stdlib.h>
#include "Config.h"

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
  myFile << "Name:" << name << "\n";
  myFile << "Secret combination:" << game->getSecretCombination()->toString() << "\n";
  myFile << "Number of rounds:" << game->getPlayedRounds() << "\n";
  for (int i = 0; i < game->getPlayedRounds(); i++) {
    myFile << "Round " << i << ":" << game->getRounds().at(i).first->toString() 
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
    config.insert_or_assign(key, value);
  }
  return 0;
}

void FileIO::loadGame(string name, MasterMind* game) {
  string fileName = Config::getInstance()->getSaveGamePath() + name;
  map<string, string> configuration;
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "Unable to open the selected game file " << name << endl;
    game->setState(State::OUT_GAME);
    return;
  }
  game->setState(State::IN_GAME);
  string line, value;
  int lineNumber = 1;
  getline(file, line);
  getline(file, line);
  value = getNextValue(line);
  SecretCombination *secret = new SecretCombination(value);
  game->setSecretCombination(secret);
  getline(file, line);
  value = getNextValue(line);
  int playedRounds = std::stoi(value);
  game->setPlayedRounds(playedRounds);
  for (int i = 0; i < playedRounds; i++) {
    if (getline(file, line)) {
      value = getNextValue(line);
      game->setRound(value);
    }
    else {
      cout << "Error loading the game:" << name << endl;
      game->setState(State::OUT_GAME);
    }
  }
}

string FileIO::getNextValue(string line) {
  string splitter = ":";
  size_t pos = line.find(splitter);
  string aux = line.substr(pos + 1, line.size());
  return aux;
}
