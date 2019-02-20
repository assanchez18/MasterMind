#include "Config.h"
#include "FileIO.h"

Config* Config::config_ = nullptr;

Config* Config::getInstance(string file) {
  if (config_ == nullptr) {
    config_ = new Config(file);
  }
  return config_;
}

Config::Config(string file)
  : configFile_(file){
}

Config::~Config() {
}
void Config::loadConfig() {
  FileIO fio;
  fio.readConfig(configFile_, '=', configuration);


  //TO-DO: LOAD CONFIGURATION FROM FILE

}
