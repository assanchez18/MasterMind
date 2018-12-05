#include "pch.h"
#include "AddCombinationView.h"


AddCombinationView::AddCombinationView()
{
}


AddCombinationView::~AddCombinationView()
{
}

void AddCombinationView::interact(AddCombinationController* controller)
{
	controller->action();
}
