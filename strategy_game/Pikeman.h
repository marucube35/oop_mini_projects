#pragma once
#include <sstream>
using namespace std;

#include "IAttackable.h"
#include "Soldier.h"
#include "Swordman.h"
#include "Knight.h"

class Pikeman : public Soldier {
public:
	Pikeman() {
		_hp = 800;
		_atk = 8;
	}
	string toString() {
		stringstream builder;
		builder << "Pikeman: HP=" << _hp;
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