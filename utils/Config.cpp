#include "Config.h"
#include "FileIO.h"

Config* Config::config_ = nullptr;

Config* Config::getInstance() {
  if (config_ == nullptr) {
    config_ = new Config();
  }
  return config_;
}

Config::Config()
  : configFile_(){
}

Config::~Config() {
  delete config_;
}
void Config::loadConfig() {
  FileIO fio;
  fio.readConfig(configFile_, '=', configuration);
}

string Config::getSaveGamePath() {
  return config_->configuration.at("gamesPath");
}

void Config::setConfigFile(string file) {
  configFile_ = file;
}
