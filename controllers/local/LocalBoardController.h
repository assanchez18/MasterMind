#pragma once
#include "BoardController.h"
#include "LocalOperationController.h"
namespace controllers {
namespace locals {
class LocalBoardController
  : public BoardController, public LocalOperationController
{
public:
  LocalBoardController(MasterMind* game);
  ~LocalBoardController();

  virtual std::vector<Round*>& getRounds() override;
  virtual int getPlayedRounds() override;
  virtual void action(bool victory) override;
  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
  bool isFinished();

private:
  bool finished;
};

}
}