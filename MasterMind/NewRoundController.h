#pragma once

class PlayerCombination;

class NewRoundController 
{
public:
	virtual void addRound(PlayerCombination* playerCombination) = 0;
};
