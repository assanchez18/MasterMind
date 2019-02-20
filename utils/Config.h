#pragma once
#include <string>
#include <map>
using namespace std;

class Config {
private:
  Config();
  static Config* config_;
  map<string, string> configuration;
  string configFile_;

public:
  static Config* getInstance();
  ~Config();
  void loadConfig();
  string getSaveGamePath();
  void setConfigFile(string file);

};

