#include "LocalMenuController.h"

#include "FactoryMenu.h"

LocalMenuController::LocalMenuController(MasterMind * game)
	: LocalOperationController(game)
{
}

LocalMenuController::~LocalMenuController()
{
	delete menu;
}

void LocalMenuController::createMenu()
{
	delete menu;
	menu = FactoryMenu::createMenu(&game->getState(), game);
}

inline std::vector<Command*> LocalMenuController::getCommands()
{
	return menu->getCommands();
}

void LocalMenuController::accept(IOperationControllerVisitor * operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

void LocalMenuController::execute(int command)
{
	//menu->execute(command);
}
