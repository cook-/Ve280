#include "world_type.h"
#include "simulation.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int
main(int argc, char *argv[])
{
	try {
		if (argc < 4) throw argc;
	}
	catch (int &e) {
		cout << "Error: Missing arguments!\n"
		  << "Usage: ./p3 <species-summary> <world-file> <rounds> [v|verbose]" 
		  << endl;
		throw;
	}

	try {
		if (atoi(argv[3]) < 0) throw atoi(argv[3]);
	}
	catch (int &e) {
		cout << "Error: Number of simulation rounds is negative!" << endl;
		throw;
	}

	string speciesFile = argv[1];
	string worldFile = argv[2];
	int roundNum = atoi(argv[3]);
	bool verbose = (argc == 4) ? 
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