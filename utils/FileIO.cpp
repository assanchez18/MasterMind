#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

FileIO::FileIO() {
}


FileIO::~FileIO() {
}

void FileIO::saveGame(MasterMind * game, string name) {
  ofstream myFile;
  const char* pathForGames("");
  myFile.open("$(FileSavePath)" + name);
  myFile << "example sentence\n";
  myFile.close();
}

int FileIO::readConfig(string fileName, const char splitter, map<string,string> &config) {
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
    if (config.count(key) > 0) {
      cout << "Duplicated config attribute " << key << endl;
      return -1;
    }
    config.insert_or_assign(key, value);
  }
  
}

