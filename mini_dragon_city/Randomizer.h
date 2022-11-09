#pragma once
#include <iostream>
using namespace std;


class Randomizer
{
private:
	inline static Randomizer* _instance = nullptr;
	Randomizer()
	{
		srand(time(NULL));
	}

public:
	static Randomizer* getInstance()
	{
		if (_instance == nullptr)
			_instance = new Randomizer();
		return _instance;
	}

	int next(int left, int right)
	{
		return rand() % (right - left + 1) + left;
	}

};