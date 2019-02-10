#pragma once
#include "OutGameView.h"
#include "FactoryMenu.h"

OutGameView::OutGameView() {
}


OutGameView::~OutGameView() {
}

void OutGameView::interact(OutGameController * controller) {
  Menu* outGameMenu = FactoryMenu::createMenu(controller);
  //outGameMenu->print();
  Command* command;// = outGameMenu->selectOption();
//  command->execute();
  delete outGameMenu;
//  delete command;
}
