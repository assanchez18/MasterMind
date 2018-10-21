#include "pch.h"
#include <assert.h>
#include <iostream>
#include "CloseInterval.h"
#include "CombinationColor.h"

CombinationColor::CombinationColor() {
}

CombinationColor::CombinationColor(int color) : Color::Color(color) {
	assert(&color != nullptr);
	this->color = convertToChar(color);
}

CombinationColor::CombinationColor(char color) : Color::Color(color) {
	assert(&color != nullptr);
	if (this->color == NULL) {
		switch (color) {
		case 'R':
			this->color = this->RED;
			break;
		case 'G':
			this->color = this->GREEN;
			break;
		case 'O':
			this->color = this->ORANGE;
			break;
		case 'Y':
			this->color = this->YELLOW;
			break;
		}
	}
}

CombinationColor::~CombinationColor() {
}

void CombinationColor::randomColor() {
	int randomColor = rand() % this->NUMBER_OF_COLORS;
	CombinationColor(convertToChar(randomColor));
	delete &randomColor;
}

char CombinationColor::convertToChar(int color) {
	assert(&color != nullptr);
	assert(CloseInterval::CloseInterval(0, 5).contains(color));
	char result = __super::convertToChar(color);
	if (result != NULL) {
		return result;
	}
	switch (color) {
	case 2:
		return this->RED;
	case 3:
		return this->GREEN;
	case 4:
		return this->ORANGE;
	case 5:
		return this->YELLOW;
	default:
		return NULL;
	}
}
