#include "InGameView.h"
#include "Menu.h"
#include "FactoryMenu.h"
#include "MenuView.h"


InGameView::InGameView() {
}


InGameView::~InGameView() {
}

void InGameView::interact(InGameController * controller) {
  Menu* menu = FactoryMenu::createMenu(controller);
  MenuView* view = new MenuView(menu);
  view->print();
  Command* command = menu->getCommandList().at(view->getOption());
  command->execute();
  delete menu;
  delete view;
  delete command;
}
