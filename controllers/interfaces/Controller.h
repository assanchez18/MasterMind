#pragma once
#include "Session.h"
#include "IController.h"

class Controller :
	public IController
{
public:
	Controller();
	Controller(Session* session);
	~Controller();

	virtual const int getNumberOfRounds() override;
	virtual std::vector<std::pair<Combination*, Result*>>& getRounds() override;
	virtual StateValue getState() override;

protected:
	Session* session_;
};

