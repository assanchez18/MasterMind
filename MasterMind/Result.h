#pragma once
#include <vector>
#include <map>
#include "ResultColor.h"
#include "CombinationColor.h"
#include "SecretCombination.h"

class Result
{
public:
	Result();
	Result(int size, SecretCombination* secret, std::vector<CombinationColor>* possible);
	~Result();
	void printResult();
	void check();
	bool isSolution();

private:
	int SIZE_OF_RESULT;
	SecretCombination* secret;
	std::vector<CombinationColor>* possible;
	std::vector<ResultColor> result;
	void pushResult(ResultColor color);
	void fillResult();
	void pushIntoMap(std::map<char, std::vector<int>>& map, char key, int value);
	void loadSetOfPosition(std::map<char, std::vector<int>>& map, std::vector<CombinationColor>* combination);
	bool containsPosition(std::vector<int> &positions, const int position);
	void compareVectors(std::vector<int> secret, std::vector<int> possible);
	bool containsColor(std::map<char, std::vector<int>> map, char color);
	void printVictory();
};