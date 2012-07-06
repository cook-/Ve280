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
	string verboseiStr = argv[4];

	bool verbose = (verboseStr == "v" || verboseStr == "verbose");

	struct world_t world;
	if (initWorld(world, speciesFile, worldFile)) {
		// start simulation
		cout << "Initial state" << endl;
		printGrid(world.grid);
		for (int i = 1; i != roundNum+1; ++i) {
			cout << "Round " << i << endl;
			for (int j = 0; j != world.numCreatures; ++j)
				simulateCreature(world.creatures[j], grid, verbose);

		}
	}
	return 0;
}
