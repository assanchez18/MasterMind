#include "CloseInterval.h"
#include <assert.h>

CloseInterval::CloseInterval(int min, int max)
{
	assert(&min != nullptr);
	assert(&max != nullptr);
	assert(min <= max);
	this->min = min;
	this->max = max;
}

CloseInterval::~CloseInterval()
{
}

int CloseInterval::getMin()
{
	return this->min;
}

int CloseInterval::getMax()
{
	return this->max;
}

bool CloseInterval::contains(int value)
{
	return (this->min <= value) && (this->max >= value);
}
