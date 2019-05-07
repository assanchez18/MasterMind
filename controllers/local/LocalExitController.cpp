#include "LocalExitController.h"



LocalExitController::LocalExitController(Session* session)
  : Controller(session)
{
}


LocalExitController::~LocalExitController() {
}

void LocalExitController::exitGame() {
  session_->next();
}
