#pragma once
#include <string>
using namespace std;

class Soldier {
protected:
	int _hp;
	int _atk;

public:
	int hp() { return _hp; }
	int atk() { return _atk; }
	void setHp(int value) { _hp = value; }
	void setAtk(int value) { _atk = value; }
	bool isAlive() { return _hp > 0; }

public:
	virtual void attack(Soldier* opponent) = 0;
	virtual string toString() = 0;
};