#include "world_type.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

bool 
initWorld(world_t &world, const string &speciesFile,
	const string &worldFile)
{
	ifstream iFile;
	istringstream iStream;
	string line;

	iFile.open(speciesFile);

	string title
	getline(iFile, title);
	int i = 0;
	while (iFile)
		getline(iFile, world.species[i++].name);	//initialize name.
	world.numSpecies = i;		// initialize numSpecies.

	iFile.close();

	for (int i = 0; i != numSpecies; ++i) {
		iFile.open(world.species[i].name.c_str());

		getline(iFile, line);

		while (line != "\n") {
			int j = 0
			iStream.clear();
			iStream.str(line);

			string opName;
			iStream >> opName;
			world.species[i].program[j].op = findOpcode(opName);	// initialize op.

			if (opName == "ifempty" || opName == "ifenemy" || opName == "ifsame"			  || opName == "ifwall" || opName == "go")
				iStream >> world.species[i].program[j].address;		// initialize address.

			j++;
		}

		programSize = j;	// initialize programSize.

		iFile.close();
	}

	iFile.open(worldFile);

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.height;	// initialize height.

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.width;	// initialize width.

	while (iFile) {
		int i = 0;
		getline(iFile, line);
		iStream.clear();
		iStream.str(line);
		iStream >> name >> dir >> creatures[i].location.r >> creatures[i].location.c;	// initialize r& c.
		creatures[i].direction = fineDir(dir);	// initialize direction.
		creatures[i].species = world.species + findSpeciesIndex(name);	// initialize *species.
		programID = 1;	// initialize programID.
		square[r][c] = creature + i;	// initialize squares.
		i++;
	}
}

void 
simulateCreature(creature_t &creature, grid_t &grid, bool verbose)
{
	// update the creature(program is always updated)
	
	// update the infected creature
	// update the grid
	// print to the stdout
	cout << "Creature (" 
		 << (creature -> species) -> name 
		 << directName[creature.direction] 
		 << creature.location.r 
		 << creature.location.c
		 << ") takes action: " 
		 << 
		 << endl;
	if (verbose)
		printGrid(grid);
}

void 
printGrid(const grid_t &grid)
{
	for (int i = 0; i != grid.height; ++i) {
		for (int j = 0; j != grid.width; ++j) {
			if (grid.squares[i][j] == NULL)
				cout << "____ ";
			else
				cout << (grid.squares[i][j] -> species) -> name[0] 
				     << (grid.squares[i][j] -> species) -> name[1]
					 << "_"
					 << directShortName[grid.squares[i][j] -> direction];
		}
		cout << endl;
	}
}

point_t 
adjacentPoint(point_t pt, direction_t dir)
{
	switch (dir)
	{
		case (EAST):
			pt.c++;
		break;

		case (SOUTH):
			pt.r--;
		break;

		case (WEST):
			pt.c--;
		break;

		case (NORTH):
			pt.r++;
		break;

		default:
			;
	}
	return pt;
}

direction_t 
leftFrom(direction_t dir)
{
	if (dir == EAST)
		dir = NORTH;
	else
		dir--;
	return dir;
}

direction_t 
rightFrom(direction_t dir)
{
	if (dir == NORTH)
		dir = EAST;
	else
		dir++;
	return dir;
}

instruction_t 
getInstruction(const creature_t &creature)
{
	return creature.species -> program[creature.programID];
}

creature_t 
*getCreature(const grid_t &grid, point_t location)
{
	return grid.squares[location.r][location.c];
}

