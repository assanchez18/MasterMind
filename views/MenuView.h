#pragma once
#include "Menu.h"


class MenuView
{
public:
	MenuView(Menu* menu);
	~MenuView();

	void print();
  int getOption();
private:
  Menu* menu_;
};

