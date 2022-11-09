#pragma once
#define TYPE_NUMBERS 2
#include <iostream>
#include <string>
#include "Randomizer.h"
using namespace std;

class DragonType
{
public:
	inline static int SEA_DRAGON = 1;
	inline static int FLAME_DRAGON = 2;
};

class Dragon
{
protected:
	string _name;
	int _level;
	int _hp;
	int _baseDamage;

public:
	string Name() const { return _name; }
	int Level() const { return _level; }
	int HP() const { return _hp; }
	int BaseDamage() const { return _baseDamage; }

public:
	Dragon();

public:
	void input();
	virtual void output();
	virtual int calcDamage() = 0;
};

class SeaDragon : public Dragon
{
public:
	SeaDragon();
	SeaDragon(const Dragon&);
	SeaDragon(string name, int level);
	
public:
	void output();
	int calcDamage();

};

class FlameDragon : public Dragon {

public:
	FlameDragon();
	FlameDragon(string name, int level);

public:
	void output();
	int calcDamage();
};
