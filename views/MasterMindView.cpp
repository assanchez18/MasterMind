#include "MasterMindView.h"
#include <assert.h>


MasterMindView::MasterMindView()
{
}


MasterMindView::~MasterMindView()
{
}

void MasterMindView::interact(IOperationController * controller)
{
	controller->accept(this);
}

void MasterMindView::visit(RoundController* controller)
{	
	roundView.interact(controller);
}

void MasterMindView::visit(StartController* controller)
{
	startView.interact(controller);
}

void MasterMindView::visit(BoardController * controller)
{
	boardView.interact(controller);
}

void MasterMindView::visit(MenuController* controller)
{
	menuView.interact(controller);
}
