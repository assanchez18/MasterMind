#include "MenuView.h"
#include "CloseInterval.h"
#include <iostream>
#include <assert.h>
using namespace std;

MenuView::MenuView(Menu* menu)
  : menu_(menu)
{
}


MenuView::~MenuView()
{
}

void MenuView::print() {
  int i = 1;
  for (Command* command : menu_->getCommandList()) {
    cout << i << " - " << command->getTitle() << endl;
    i++;
  }
}

int MenuView::getOption() {
  int option = -1;
  do {
    cout << "Select an option: ";
    cin >> option;
  } while (!CloseInterval::CloseInterval(0, unsigned(menu_->getCommandList().size())).contains(option));
  return (option -1);
}
