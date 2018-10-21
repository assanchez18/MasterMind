#include "pch.h"
#include <assert.h>
#include "ResultColor.h"

ResultColor::ResultColor(char color) : Color::Color(color){
	assert(&color != nullptr);
	if (this->color == NULL) {
		this->color = this->NO_COLOR;
	}
}

ResultColor::~ResultColor()
{
}