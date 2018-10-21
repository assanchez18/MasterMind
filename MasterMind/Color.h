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
	inline bool operator<(Color& color) {
		return false;
	}
protected:
	char color;
	char convertToChar(int color);
};