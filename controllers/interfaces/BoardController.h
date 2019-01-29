#pragma once
#include <vector>
#include "Round.h"

namespace controllers {
class BoardController
{
public:
  virtual std::vector<Round*>& getRounds() = 0;
  virtual int getPlayedRounds() = 0;
  virtual void action(bool victory) = 0;
  virtual bool isFinished() = 0;
};
}