#pragma once
#include <vector>
#include <map>
#include "ResultColor.h"
#include "CombinationColor.h"
#include "SecretCombination.h"

class Result
	: public Combination
{
public:
	Result(SecretCombination* secret, Combination* player);
	~Result();
	
	bool isSolution();

private:
	void createResult(SecretCombination* secret, Combination* playerCombination);
	
	void pushIntoMap(std::map<char, std::vector<int>>& map, char key, int value);
	void loadSetOfPosition(std::map<char, std::vector<int>>& map, std::vector<Color*>& combination);
	bool containsPosition(std::vector<int> &positions, const int position);
	void compareVectors(std::vector<int> secret, std::vector<int> possible);
	bool containsColor(std::map<char, std::vector<int>> map, char color);
	void fillResult();

};