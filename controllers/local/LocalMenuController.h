#pragma once
#include "MenuController.h"
#include "LocalOperationController.h"
#include "Menu.h"
#include "StartGameCommand.h"
namespace controllers {
namespace locals {
class LocalMenuController
  : public MenuController, public LocalOperationController
{
public:
  LocalMenuController(MasterMind* game);
  ~LocalMenuController();

  virtual void createMenu() override;
  virtual std::vector<Command*> getCommands() override;
  void execute(int command) override;

  virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;

private:
  Menu* menu;
};

}
}