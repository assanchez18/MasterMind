#include "LocalStartController.h"

LocalStartController::LocalStartController(Session * session)
	: Controller(session)
{
}

LocalStartController::~LocalStartController()
{
}

void LocalStartController::start()
{
	session_->startGame();
}

const int LocalStartController::getNumberOfRounds() {
	return session_->getMaxRounds();
}

