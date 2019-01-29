#pragma once
#include "Color.h"
class ColorView
{
public:
	ColorView(Color* color);
	~ColorView();
	void interact();
private:
	Color* color;
	void printColor();

};

