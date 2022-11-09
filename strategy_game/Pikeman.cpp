#include "Pikeman.h"

// ===== PIKEMAN ======

void Pikeman::attack(Soldier* opponent) {
	if (typeid(Swordman) == typeid(*opponent)) {
		((Swordman*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordman*)opponent);
		}
	}
	else if (typeid(Knight) == typeid(*opponent)) {
		((Knight*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}
}

void Pikeman::hitBy(Swordman* opponent) {
	_hp = _hp - (opponent->atk() + 12);
}

void Pikeman::hitBy(Knight* opponent) {
	_hp = _hp - opponent->atk();
}

void Pikeman::hitBy(Pikeman* opponent) {
	_hp = _hp - opponent->atk();
}