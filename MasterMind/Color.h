#pragma once
class Color
{
public:
	static const char WHITE = 'W';
	static const char BLACK = 'B';
	static const int NUMBER_OF_COLORS = 2;
	
	Color();
	Color(int color);
	Color(char color);
	~Color();

	char getColor();
	bool isEqual(Color color);
	bool isValid();

protected:
	char color;
	char convertToChar(int color);
	char convertToUpper(char &color);
};