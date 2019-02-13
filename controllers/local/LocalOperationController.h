#pragma once
#include "IOperationController.h"

class LocalOperationController
  : public IOperationController {
public:
  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) = 0;
};