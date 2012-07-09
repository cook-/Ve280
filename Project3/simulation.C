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

			string operName;
			iStream >> operName;
			world.species[i].program[j].op = findOpcode(operName);	// initialize op.

			if (operName == "ifempty" || operName == "ifenemy" || operName == "ifsame" || operName == "ifwall" || operName == "go")
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
simulateCreature(unsigned int i, world_t &world, bool verbose)
{
	//follow one instruction
	instuction_t ins = getInstruction(creature);
	switch (ins)
	{
		case HOP:		hop(i, world);		break;
		case LEFT:		left(i, world);		break;
		case RIGHT:		right(i, world);	break;
		case INFECT:	infect(i, world);	break;
		case IFEMPTY:	ifempty(i, world);	break;
		case IFENEMY:	ifenemy(i, world);	break;
		case IFSAME:	ifsame(i, world);	break;
		case IFWALL:	ifwall(i, world);	break;
		case GO:		go(i, world);		break;
		defalut: ;
	}
	cout << "Creature (" 
		 << (world.creatures[i] -> species) -> name 
		 << directName[world.creatures[i].direction] 
		 << world.creature[i].location.r 
		 << world.creature[i].location.c
		 << ") takes action:" 
	
	if (verbose) {
		cout << endl << "Instruction " << world.creature[i].programID << ": "
		printGrid(grid);
	}

	else {

	}
		
}

opcode_t
findOpcode(const string operName)
{
	opcode_t opcode;
	for (int i = 0; i != 9; ++i)
		if (operName == opName[i])
			opcode = i;
	return opcode;
}

direction_t
findDir(const string dir)
{
	direction_t direction;
	for (int i = 0; i != 4; ++i)
		if (dir == direcName[i])
			direction = i;
	return direction;
}

unsigned int
findSpeciesIndex(world_t &world, string name)
{
	unsigned int index;
	for (int i = 0; i != world.numSpecies; i++)
		if (name == world.species[i].name)
			index = i;
	return index;
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

