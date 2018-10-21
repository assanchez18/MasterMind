#pragma once
#include <vector>
#include "CombinationColor.h"

class Combination
{
public:
	Combination();
	~Combination();
	std::vector<CombinationColor>* getCombination();
	void pushColorToCombination(CombinationColor* color);
	CombinationColor getPosition(int position);
	int getSizeOfCombination();
	CombinationColor getColorAt(int position);
	void printCombination();

protected:
	const static int SIZE_OF_COMBINATION = 5;
	std::vector<CombinationColor> combination[SIZE_OF_COMBINATION];
	int getSize();
	bool comparePositionColor(int position, Combination* combinationToCheck);
	bool isSameSize(Combination* combination);

};

