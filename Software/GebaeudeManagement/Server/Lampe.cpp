#include "Lampe.h"

Lampe::Lampe() {
	Actor::setId(2);
}

Lampe::~Lampe() {
	;
}

void Lampe::setState(bool p_action) {
	Actor::setState(p_action);
}

bool Lampe::getState(){
	bool state = Actor::getState();
	return state;
}

void Lampe::setName(string p_name) {
	this->name = p_name;
}
string Lampe::getName() {
	return this->name;
}


