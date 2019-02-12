#pragma once
#include "OutGameView.h"
#include "MenuView.h"
#include "FactoryMenu.h"

OutGameView::OutGameView() {
}


OutGameView::~OutGameView() {
}

void OutGameView::interact(OutGameController * controller) {
  Menu* menu = FactoryMenu::createMenu(controller);
  MenuView* view = new MenuView(menu);
  view->print();
  Command* command = menu->getCommandList().at(view->getOption());
  command->execute();
  delete menu;
  delete view;
  delete command;
}
