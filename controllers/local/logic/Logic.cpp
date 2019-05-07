#include "Logic.h"

Logic::Logic() {
	controllers_.emplace(StateValue::INITIAL, new LocalOutGameController(&session_));
	controllers_.emplace(StateValue::IN_GAME, new LocalInGameController(&session_));
}

Logic::~Logic() {
}


LocalOperationController* Logic::getController() {
  
}

