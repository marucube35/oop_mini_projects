#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "IAttackable.h"
#include "Soldier.h"
#include "Swordman.h"
#include "Knight.h"
#include "Pikeman.h"

int main()
{
	Soldier* sword1 = new Swordman();
	Soldier* sword2 = new Swordman();
	Soldier* knight = new Knight();
	Soldier* pike = new Pikeman();

	knight->attack(sword1);
	knight->attack(sword2);
	knight->attack(pike);

	cout << sword1->toString() << endl;
	cout << sword2->toString() << endl;
	cout << knight->toString() << endl;
	cout << pike->toString() << endl;

	return 0;
}