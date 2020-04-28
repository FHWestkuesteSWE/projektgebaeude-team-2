#include "Actor.h"

Actor::Actor() {
}

Actor::Actor(int _id) {
	id = _id;
}

Actor::~Actor() {

}

void Actor::setState(bool _action) {

	// Set new state to user action, e.g On (True), Off (False)
	state = _action;

}

bool Actor::getState() {
	return state;
}