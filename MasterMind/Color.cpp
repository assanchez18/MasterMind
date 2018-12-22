#include "pch.h"
#include <assert.h>
#include <iostream>
#include "Color.h"
#include "CloseInterval.h"

Color::Color()
{
}

Color::Color(int color)
{
	assert(&color != nullptr);
	Color(convertToChar(color));
}

Color::Color(char color) {
	assert(&color != nullptr);
	color = convertToUpper(color);
	switch (color) {
	case 'W':
		this->color = this->WHITE;
		break;
	case 'B':
		this->color = this->BLACK;
		break;
	default:
		this->color = NULL;
		break;
	}
}

Color::~Color()
{
}

char Color::convertToChar(int color) {
	assert(&color != nullptr);
	switch (color) {
	case 0:
		return this->WHITE;
	case 1:
		return this->BLACK;
	default:
		return NULL;
	}
}

bool Color::isValid() {
	if (this->color != NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

char Color::getColor() {
	return this->color;
}

bool Color::isEqual(Color* color) {
	assert(&color != nullptr);
	return this->color == color->getColor();

}

char Color::convertToUpper(char &color) {
	return color &= ~' ';
}