#pragma once
#include <vector>
#include "Combination.h"
#include "Result.h"
using namespace std;

class Memento
{
public:
	Memento(pair<Combination*, Result*> roundToSave);
	~Memento();
	pair<Combination*, Result*> getRound();
private:
	pair<Combination*, Result*> round_;
};
