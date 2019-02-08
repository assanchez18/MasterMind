#include "OutGameView.h"
#include "FactoryMenu.h"

OutGameView::OutGameView()
{
}


OutGameView::~OutGameView()
{
}

void OutGameView::interact(OutGameController * controller) {
	Menu* outGameMenu = FactoryMenu::createMenu(controller);
	//CRAR VISTA MENU OUITGAME
	//pedir INFO 
	//EJECUTAR COMAND
}
