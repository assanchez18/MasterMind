#pragma once
#include <vector>
#include "CombinationColor.h"

class Combination
{
public:
	Combination();
	Combination(std::string combination);
	~Combination();

	void pushColorToCombination(Color* color);

	std::vector<Color*>& getCombination();
	Color* getPosition(int position);
	static int getSizeOfCombination(){ return SIZE_OF_COMBINATION; }
	Color* getColorAt(int position);
  virtual std::string toString();

protected:
	const static int SIZE_OF_COMBINATION = 5;
	std::vector<Color*> combination;
	
	int getSize();
	bool isSameSize(Combination* combination);
	bool comparePositionColor(int position, Combination* combinationToCheck);

};

