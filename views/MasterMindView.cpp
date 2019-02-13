#include "MasterMindView.h"
#include <assert.h>


MasterMindView::MasterMindView()
{
}


MasterMindView::~MasterMindView()
{
}

void MasterMindView::interact(IOperationController * controller) {
  controller->accept(this);
}

void MasterMindView::visit(OutGameController* controller)
{
	outGameView_.interact(controller);
}

void MasterMindView::visit(InGameController* controller) {
  inGameView_.interact(controller);
}
