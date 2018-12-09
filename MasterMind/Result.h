#pragma once
#include <vector>
#include <map>
#include "ResultColor.h"
#include "CombinationColor.h"
#include "SecretCombination.h"
#include "PlayerCombination.h"

class Result
{
public:
	Result(SecretCombination* secret, PlayerCombination* player);
	~Result();
	
	//TO-DO: REMOVE
	void printResult();
	bool isSolution();
	
private:
	int SIZE_OF_RESULT;
	std::vector<ResultColor> result;
	void createResult(SecretCombination* secret, PlayerCombination* playerCombination);
	
	void pushIntoMap(std::map<char, std::vector<int>>& map, char key, int value);
	void loadSetOfPosition(std::map<char, std::vector<int>>& map, std::vector<CombinationColor>* combination);
	bool containsPosition(std::vector<int> &positions, const int position);
	void compareVectors(std::vector<int> secret, std::vector<int> possible);
	bool containsColor(std::map<char, std::vector<int>> map, char color);
	void pushResult(ResultColor color);
	void fillResult();

	//TO-DO: REMOVE
	void printVictory();
};