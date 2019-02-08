#include "LocalLoadGameController.h"



LocalLoadGameController::LocalLoadGameController() {
}


LocalLoadGameController::~LocalLoadGameController() {
}

void LocalLoadGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
  operationControllerVisitor->visit(this);
}

void LocalLoadGameController::load() {

}
