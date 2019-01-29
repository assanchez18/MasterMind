#pragma once
#include "IOperationController.h"
#include "Controller.h"
#include "MasterMind.h"

namespace controllers {
namespace locals {
class LocalOperationController
  : public IOperationController, public Controller
{
public:
  LocalOperationController(MasterMind* game);
  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) = 0;

};
}
}