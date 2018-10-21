#pragma once
#include "Color.h"
class CombinationColor :
	public Color
{
public:
	static const char RED = 'R';
	static const char YELLOW = 'Y';
	static const char ORANGE = 'O';
	static const char GREEN = 'G';
	static const int NUMBER_OF_COLORS = __super::NUMBER_OF_COLORS + 4;

	CombinationColor();
	CombinationColor(int color);
	CombinationColor(char color);
	~CombinationColor();

	void randomColor();
	char convertToChar(int color);

};

