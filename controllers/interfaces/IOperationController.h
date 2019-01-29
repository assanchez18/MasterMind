#pragma once
#include "IOperationControllerVisitor.h"
namespace controllers {
class IOperationController {
public:
  virtual void accept(IOperationControllerVisitor* operationControllerVisitor) = 0;
};
}