#pragma once
#include "MenuController.h"
#include "LocalOperationController.h"
#include "Menu.h"
#include "StartGameCommand.h"

class LocalMenuController
	: public MenuController
{
public:
	LocalMenuController(MasterMind* game);
	~LocalMenuController();

	virtual void createMenu() override;
	inline virtual std::vector<Command*> getCommands() override;
	void execute(int command) override;

	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;	

private:
	Menu* menu;
};

