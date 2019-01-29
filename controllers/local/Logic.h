#pragma once
#include <map>
#include "MasterMind.h"
#include "State.h"
#include "LocalStartController.h"
#include "LocalRoundController.h"
#include "LocalBoardController.h"
using namespace controllers;
using namespace controllers::locals;
using namespace models;
namespace logic {

class Logic
{
public:
  Logic();
  ~Logic();

  IOperationController* getController(State state);
  LocalOperationController* getController();
  void changeState();
  bool isEnd();

private:
  MasterMind game;
  LocalStartController* startController;
  LocalRoundController* roundController;
  LocalBoardController* boardController;
  State getState();

  std::map<State, IOperationController*> controllers;
};

}