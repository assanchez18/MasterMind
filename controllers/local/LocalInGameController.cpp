#include "LocalInGameController.h"
#include "LocalRoundController.h"
#include "LocalSaveGameController.h"
#include "LocalExitController.h"
#include "LocalRedoController.h"
#include "LocalUndoController.h"

LocalInGameController::LocalInGameController(Session* session)
	: Controller(session) {
	roundController_ = new LocalRoundController(session);
	saveController_ = new LocalSaveGameController(session);
	redoController_ = new LocalRedoController(session);
	undoController_ = new LocalUndoController(session);
	exitController_ = new LocalExitController(session);
}


LocalInGameController::~LocalInGameController() {
}

void LocalInGameController::addRound(Combination* combination) {
	roundController_->addRound(combination);
}

bool LocalInGameController::isGameFinished() {
	return roundController_->isGameFinished();
}

void LocalInGameController::saveGame(std::string gameName) {
	saveController_->saveGame(gameName);
}

void LocalInGameController::exitGame() {
	exitController_->exitGame();
}

bool LocalInGameController::redoable() {
	return redoController_->redoable();
}

bool LocalInGameController::undoable() {
	return undoController_->undoable();
}

void LocalInGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}
