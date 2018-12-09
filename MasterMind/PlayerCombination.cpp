#include "pch.h"
#include <iostream>
#include <assert.h>
#include "PlayerCombination.h"


PlayerCombination::PlayerCombination()
{
}

PlayerCombination::PlayerCombination(SecretCombination* secret)
{
	createResult(secret);
}

PlayerCombination::~PlayerCombination()
{
}