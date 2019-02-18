#include "Menu.h"
#include "ExitCommand.h"

Menu::Menu() {
}


Menu::~Menu() {
}

std::vector<Command*> Menu::getCommandList() {
  return commandList_;
}

