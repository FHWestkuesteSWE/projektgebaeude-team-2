#include "Actor.h"

Actor::Actor() {
	this->id = 0;
	this->state = false;
}


Actor::~Actor() {

}

void Actor::setId(int p_id) {
	this->id = p_id;
}

void Actor::setState(bool p_action) {
	this->state = p_action;
}

bool Actor::getState() {
	return state;
}