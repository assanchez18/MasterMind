#include "AddRoundCommand.h"
#include "RoundView.h"
#include "BoardView.h"

AddRoundCommand::AddRoundCommand(std::string title, InGameController* controller)
  : InGameCommand(title, controller) {
}


AddRoundCommand::~AddRoundCommand() {
}

void AddRoundCommand::execute() {
  RoundView* roundView = new RoundView();
  Combination* combination = roundView->requestCombination();
  controller_->addRound(std::move(combination));
  BoardView* boardView = new BoardView();
  boardView->interact(controller_);
  delete boardView;
  delete roundView;
}

bool AddRoundCommand::isActive() {
	return controller_->isGameFinished();
}
