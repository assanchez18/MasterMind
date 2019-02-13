#pragma once
#include "BoardController.h"
#include "LocalOperationController.h"
#include "Controller.h"

class LocalBoardController
  : public BoardController, public Controller {
public:
  LocalBoardController(MasterMind* game);
  ~LocalBoardController();

  virtual std::vector<pair<Combination*, Result*>>& getRounds() override;
  virtual int getPlayedRounds() override;
  virtual void action(bool victory) override;
  bool isFinished();

private:
  bool finished;
};

