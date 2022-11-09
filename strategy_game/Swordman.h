#pragma once
#include <sstream>
using namespace std;

#include "IAttackable.h"
#include "Soldier.h"
#include "Knight.h"
#include "Pikeman.h"

class Swordman : public Soldier, public IAttackable {
public:
	Swordman() {
		_hp = 1000;
		_atk = 12;
	}
	string toString() {
		stringstream builder;
		builder << "Swordman: HP=" << _hp;
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