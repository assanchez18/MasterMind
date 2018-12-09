#include "pch.h"
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

void MasterMindView::visit(NewRoundController* controller)
{
	newRoundView.interact(controller);
}

void MasterMindView::visit(StartController * controller)
{
	startControllerView.interact(controller);
}


