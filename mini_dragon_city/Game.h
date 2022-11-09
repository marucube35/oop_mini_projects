#pragma once
#include <vector>
#include "Dragon.h"
using namespace std;

class Game
{
private:
	vector<Dragon*> _dragons;

public:
	Dragon* createDragon(int);
	void inputDragons();
	void outputDragons();
	int calcTotalDamage();
};

