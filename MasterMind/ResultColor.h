#pragma once
#include "Color.h"
class ResultColor :
	public Color
{
public:
	static const char NO_COLOR = 'N';
	
	ResultColor(char color);
	~ResultColor();

private:
	static const int NUMBER_OF_COLORS = __super::NUMBER_OF_COLORS + 1;
};

