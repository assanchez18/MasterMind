#pragma once
#include <assert.h>
#include "CloseInterval.h"
#include "ControllerState.h"
#include "StartController.h"
#include "ClearGameController.h"
#include "CheckResultController.h"
#include "AddCombinationController.h"
#include "EndGameController.h"

class FactoryController
{
public:
	~FactoryController() {}
	static FactoryController *getInstance() {
		static FactoryController instance;
		return &instance;
	}
	Controller* getController(ControllerState state, MasterMind* game)
	{
		assert(&state != nullptr);
		assert(game != nullptr);
		assert(CloseInterval::CloseInterval(0, ControllerState::NUMBER_OF_STATES).contains(state.getState()));
		
		switch (state.getState()) {
		case 0:
			return new StartController(game);
		case 1:
			return new ClearGameController(game);
		case 2:
			return new CheckResultController(game);
		case 3:
			return new AddCombinationController(game);
		case 4:
			return new EndGameController(game);
		default:
			return nullptr;
		}
		
	}
private:
	FactoryController() {}
	FactoryController(const FactoryController &) {}
	FactoryController &operator=(const FactoryController &) { return *this; }

};

