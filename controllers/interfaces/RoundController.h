#pragma once
#include <vector>
class Combination;
namespace controllers {
class RoundController
{
public:
  virtual void addRound(Combination* playerCombination) = 0;
};
}