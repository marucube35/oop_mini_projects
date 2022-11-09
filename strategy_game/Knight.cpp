#include "Knight.h"

// ===== KNIGHT ======

void Knight::attack(Soldier* opponent) {
	if (typeid(Swordman) == typeid(*opponent)) {
		((Swordman*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordman*)opponent);
		}
	}
	else if (typeid(Knight) == typeid(*opponent)) {
		((Knight*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}
}

void Knight::hitBy(Swordman* opponent) {
	_hp = _hp - opponent->atk();
}

void Knight::hitBy(Knight* opponent) {
	_hp = _hp - opponent->atk();
}

void Knight::hitBy(Pikeman* opponent) {
	_hp = _hp - (opponent->atk() + 25);
}