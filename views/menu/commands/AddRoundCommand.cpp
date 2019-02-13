#include "AddRoundCommand.h"
#include "RoundView.h"

AddRoundCommand::AddRoundCommand(std::string title, InGameController* controller)
  : InGameCommand(title, controller) {
}


AddRoundCommand::~AddRoundCommand() {
}

void AddRoundCommand::execute() {
  RoundView* view = new RoundView();
  Combination* combination = view->requestCombination();
  controller_->addRound(std::move(combination));
  delete view;
}
