#pragma once
#include <vector>
#include "CombinationColor.h"

class Combination
{
public:
	Combination();
	~Combination();

	void pushColorToCombination(CombinationColor color);

	std::vector<CombinationColor>* getCombination();
	CombinationColor getPosition(int position);
	int getSizeOfCombination();
	CombinationColor getColorAt(int position);
	
	void printCombination();

protected:
	const static int SIZE_OF_COMBINATION = 5;
	std::vector<CombinationColor> combination[SIZE_OF_COMBINATION];
	
	int getSize();
	bool isSameSize(Combination* combination);
	
	bool comparePositionColor(int position, Combination* combinationToCheck);

};

