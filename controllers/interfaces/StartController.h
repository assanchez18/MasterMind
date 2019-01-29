#pragma once
namespace controllers {
class StartController
{
public:
  virtual void start() = 0;
  virtual int getNumberOfRounds() = 0;
};
}