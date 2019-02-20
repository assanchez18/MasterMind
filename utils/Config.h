#pragma once
#include <string>
#include <map>
using namespace std;

class Config {
private:
  Config(string file);
  static Config* config_;
  map<string, string> configuration;

public:
  static Config* getInstance(string file);
  ~Config();
  const string configFile_;
  void loadConfig();
};

