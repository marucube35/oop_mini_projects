#pragma once
#include <sstream>
using namespace std;

#include "IAttackable.h"
#include "Soldier.h"
#include "Swordman.h"
#include "Pikeman.h"

class Knight : public Soldier, public IAttackable {
public:
	Knight() {
		_hp = 1500;
		_atk = 18;
	}
	string toString() {
		stringstream builder;
		builder << "Knight: HP=" << _hp;
		builder << ", ATK=" << _atk;

		string result = builder.str();
		return result;
	}

public:
	void attack(Soldier* opponent);
	void hitBy(Swordman*);
	void hitBy(Knight*);
	void hitBy(Pikeman*);
};