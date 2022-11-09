#include "Game.h"

Dragon* Game::createDragon(int type)
{
	if (type == DragonType::SEA_DRAGON)
	{
		return new SeaDragon;
	}
	else if (type == DragonType::FLAME_DRAGON)
	{
		return new FlameDragon;
	}
	else
	{
		return new SeaDragon(); // default is Sea Dragon
	}
}

void Game::inputDragons()
{
	cout << "How many dragons?\n";
	int n; cin >> n; cin.ignore();

	for (int i = 0; i < n; i++)
	{
		int option = 0;
		do {
		cout << "What type of dragon?\n";
		cout << "1. SeaDragon\n";
		cout << "2. FlameDragon\n";
		cin >> option; cin.ignore();
		} while (option > TYPE_NUMBERS || option < 1);

		Dragon* dragon = createDragon(option);
		dragon->input();

		_dragons.push_back(dragon);
	}
}

void Game::outputDragons()
{
	cout << "Dragons' information:\n";
	for (auto dragon : _dragons)
	{
		dragon->output();
		cout << endl;
	}
}

int Game::calcTotalDamage()
{
	int totalDamage = 0;

	for (auto dragon : _dragons)
	{
		totalDamage += dragon->calcDamage();
	}

	return totalDamage;
}