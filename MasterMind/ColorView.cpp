#include "pch.h"
#include "ColorView.h"
#include <iostream>
using namespace std;

ColorView::ColorView(Color* color)
	: color(color)
{
}


ColorView::~ColorView()
{
}

void ColorView::interact() 
{
	printColor();
}

void ColorView::printColor()
{
	cout << color->getColor();
}
