#include "world_type.h"
#include "simulation.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int
main(int argc, char *argv[])
{
	string speciesFile = argv[1];
	string worldFile = argv[2];
	int roundNum = atoi(argv[3]);
	bool verbose = (argc == 3) ? \
			false : ((string)argv[4] == "v" || (string)argv[4] == "verbose");

	world_t world;
	initWorld(world, speciesFile, worldFile);
	cout << "Initial state" << endl;
	printGrid(world.grid);
	for (int i = 0; i != roundNum; ++i) {
		cout << "Round " << i + 1 << endl;
		for (int j = 0; j != world.numCreatures;++j)
			simulateCreature(world, j, verbose);
	}

	return 0;
}
