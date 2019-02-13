#pragma once
#include "IOperationControllerVisitor.h"

class IOperationController {
public:
  virtual void accept(IOperationControllerVisitor* operationControllerVisitor) = 0;
};