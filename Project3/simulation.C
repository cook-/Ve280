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

}

void 
simulateCreature(creature_t &creature, grid_t &grid, bool verbose)
{
	cout << "Creature (" <<   <<   <<   <<   << ") takes action: " <<    << endl;
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

