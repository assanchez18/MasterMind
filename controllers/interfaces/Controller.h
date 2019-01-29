#pragma once
#include "MasterMind.h"

namespace controllers {
using MasterMind = models::MasterMind;
class Controller
{
public:
  Controller();
  Controller(MasterMind* game);
  ~Controller();

  const int getNumberOfRounds(); 
  std::vector<Round*>& getRounds();
  int getPlayedRounds();
protected:
  MasterMind* game;
};
}
