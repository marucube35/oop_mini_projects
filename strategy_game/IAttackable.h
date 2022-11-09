#pragma once

class Swordman;
class Pikeman;
class Knight;

class IAttackable {
public:
	virtual void hitBy(Swordman*) = 0;
	virtual void hitBy(Knight*) = 0;
	virtual void hitBy(Pikeman*) = 0;
};