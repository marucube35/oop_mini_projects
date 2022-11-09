#include "Dragon.h"

// ---- Dragon
Dragon::Dragon()
{
	_name = "Anonymous";
	_level = 0;
	_hp = 0;
	_baseDamage = 0;
}

void Dragon::input()
{
	cout << "Enter Dragon's information:\n";
	cout << "Name: "; getline(cin, _name);
	cout << "Level: "; cin >> _level;
	cin.ignore();
}

void Dragon::output()
{
	cout << "\tName: " << _name << "\n";
	cout << "\tLevel: "<<  _level << "\n";
	cout << "\tHP: "<< _hp << "\n";
	cout << "\tBase Damage: " << _baseDamage << "\n";
}

// ---- SeaDragon

SeaDragon::SeaDragon()
	:Dragon(){
	_hp = Randomizer::getInstance()->next(1000, 10000);
	_baseDamage = Randomizer::getInstance()->next(200, 1200);
}

SeaDragon::SeaDragon(const Dragon& other)
{
	_name = other.Name();
	_level = other.Level();
	_hp = other.HP();
	_baseDamage = other.BaseDamage();
}

SeaDragon::SeaDragon(string name, int level)
{
	_name = name;
	_level = level;
	_hp = Randomizer::getInstance()->next(1000, 10000);
	_baseDamage = Randomizer::getInstance()->next(200, 1200);
}

void SeaDragon::output()
{
	cout << "\tType: Sea Dragon\n";
	Dragon::output();
	cout << "\tTrue Damage: " << calcDamage() << "\n";
}

int SeaDragon::calcDamage()
{
	int damage = _baseDamage * 10;
	return damage;
}

// ---- Flame Dragon

FlameDragon::FlameDragon()
	:Dragon(){
	_hp = Randomizer::getInstance()->next(5000, 15000);
	_baseDamage = Randomizer::getInstance()->next(100, 1000);
}

FlameDragon::FlameDragon(string name, int level)
{
	_name = name;
	_level = level;
	_hp = Randomizer::getInstance()->next(5000, 15000);
	_baseDamage = Randomizer::getInstance()->next(100, 1000);
}

int FlameDragon::calcDamage()
{
	int damage = _baseDamage * 15;
	return damage;
}

void FlameDragon::output()
{
	cout << "\tType: Flame Dragon\n";
	Dragon::output();
	cout << "\tTrue Damage: " << calcDamage() << "\n";
}




