#include "world_type.h"
#include "simulation.h"
#include <iostream>

using namespace std;

int
main(int argc, char *argv[])
{
	string speciesFile = argv[1];
	string worldFile = argv[2];
	unsigned int roundNum = argv[3];
	string v = argv[4];

	bool verbose = (v == "v" || v== "verbose");

	struct world_t world;
	if (initWorld(world, speciesFile, worldFile)) {
		cout << "Initial state" << endl;
		printGrid(world.grid);

		for (int i = 0; i != roundNum; ++i) {
			cout << "Round " << i + 1 << endl;

			for (int j = 0; j != world.numCreatures; ++j)
				simulateCreature(j, world, verbose);
		}
	}

	return 0;
}
