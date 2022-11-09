#include "Game.h"
#include "Randomizer.h"
#include "Dragon.h"

int main()
{
	Game game;
	game.inputDragons();
	game.outputDragons();
	cout << "Total Damage: " << game.calcTotalDamage() << endl;

	return 0;
}