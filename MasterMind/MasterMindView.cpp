#include "pch.h"
#include "MasterMindView.h"
#include <assert.h>


MasterMindView::MasterMindView()
{
	addCombinationView = AddCombinationView::AddCombinationView();
}


MasterMindView::~MasterMindView()
{
}

void MasterMindView::interact(IOperatioController * controller)
{
	controller->accept(this);
}

void MasterMindView::visit(AddCombinationController* controller)
{
	addCombinationView.interact(controller);
}


