#include "Swordman.h"

// ===== SWORDMAN ======

void Swordman::attack(Soldier* opponent) {
	if (typeid(Swordman) == typeid(*opponent)) {
		((Swordman*)opponent)->hitBy((Swordman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordman*)opponent);
		}
	}
	else if (typeid(Knight) == typeid(*opponent)) {
		((Knight*)opponent)->hitBy((Swordman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Swordman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}
}

void Swordman::hitBy(Swordman* opponent) {
	_hp = _hp - opponent->atk();
}

void Swordman::hitBy(Knight* opponent) {
	_hp = _hp - opponent->atk() + 10;
}

void Swordman::hitBy(Pikeman* opponent) {
	_hp = _hp - opponent->atk();
}