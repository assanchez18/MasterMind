#include "Memento.h"

Memento::Memento(pair<Combination*, Result*> roundToSave) :
	round_(roundToSave) {
}


Memento::~Memento() {
}

pair<Combination*, Result*> Memento::getRound() {
	return round_;
}