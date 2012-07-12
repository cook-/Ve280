// test initWorld() and printGrid().

#include "world_type.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

void initWorld(world_t &, const string &, const string &);
void printGrid(const grid_t &);
void simulateCreature(world_t &, unsigned int/*, bool*/);
opcode_t findOpcode(const string &);
direction_t findDir(const string &);
species_t *findSpecies(world_t &, const string &);
instruction_t getInstruction(const creature_t &);
void hop(world_t &, unsigned int);
void left(world_t &, unsigned int);
void right(world_t &, unsigned int);
void infect(world_t &, unsigned int);
void ifempty(world_t &, unsigned int, unsigned int);
void ifwall(world_t &, unsigned int, unsigned int);
void ifsame(world_t &, unsigned int, unsigned int);
void ifenemy(world_t &, unsigned int, unsigned int);
void go(world_t &, unsigned int, unsigned int);
direction_t leftFrom(direction_t);
direction_t rightFrom(direction_t);

int
main(int argc, char *argv[])
{
	string speciesFile = argv[1];
	string worldFile = argv[2];
	int roundNum = atoi(argv[3]);

	world_t world;
	initWorld(world, speciesFile, worldFile);
	cout << "Initial state" << endl;
	printGrid(world.grid);
	for (int i = 0; i != roundNum; ++i) {
		cout << "Round " << i + 1 << endl;
		simulateCreature(world, 0);
		printGrid(world.grid);
	}

	return 0;
}

void 
initWorld(world_t &world, const string &speciesFile,
	const string &worldFile)
{

	// initialize the struct world_t.

	world.numSpecies = 0;

	for (int i = 0; i != MAXSPECIES; ++i) {
		world.species[i].name = "";
		world.species[i].programSize = 0;
		for (int j = 0; j != MAXPROGRAM; ++j) {
			world.species[i].program[j].op = HOP;
			world.species[i].program[j].address = 0;
		}
	}

	world.numCreatures = 0;
	for (int i = 0; i != MAXCREATURES; ++i) {
		world.creatures[i].location.r = 0;
		world.creatures[i].location.c = 0;
		world.creatures[i].direction = EAST;
		world.creatures[i].species = NULL;
		world.creatures[i].programID = 0;
	}

	world.grid.height = 0;
	world.grid.width = 0;
	for (int i = 0; i != MAXHEIGHT; ++i)
		for (int j = 0; j != MAXWIDTH; ++j)
			world.grid.squares[i][j] = NULL;


	// assign file data to  numSpecies and species[].

	ifstream iFile;
	istringstream iStream;
	string line;

	iFile.open(speciesFile.c_str());

	getline(iFile, line);

	int i = 0;
	while (iFile)
		getline(iFile, world.species[i++].name);
	world.numSpecies = i - 1;

	iFile.close();

	for (int i = 0; i != world.numSpecies; ++i) {

		iFile.open(world.species[i].name.c_str());

		int j = 0;
		getline(iFile, line);
		while (!line.empty()) {
			iStream.clear();
			iStream.str(line);

			string operName;
			iStream >> operName;
			world.species[i].program[j].op = findOpcode(operName);

			if (operName == "ifempty" || operName == "ifenemy" || 
		   	   operName == "ifsame" || operName == "ifwall" || operName == "go")
				iStream >> world.species[i].program[j].address;

			getline(iFile, line);
			j++;
		}
		world.species[i].programSize = j;

		iFile.close();
		getline(iFile, line);
	}


	// assign file data to numCreatures, creatures[] and grid.

	iFile.open(worldFile.c_str());

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.height;

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.width;
	
	getline(iFile, line);
	i = 0;
	while (!line.empty()) {
		iStream.clear();
		iStream.str(line);

		string name, dir;
		iStream >> name >> dir 
				>> world.creatures[i].location.r 
				>> world.creatures[i].location.c;

		world.creatures[i].direction = findDir(dir);
		world.creatures[i].species = findSpecies(world, name);
		world.creatures[i].programID = 0;
		world.grid.squares[world.creatures[i].location.r]\
						[world.creatures[i].location.c] = world.creatures + i;

		getline(iFile, line);
		i++;
	}
	world.numCreatures = i;

	iFile.close();
}

void 
printGrid(const grid_t &grid)
{
	for (int i = 0; i != grid.height; ++i) {
		for (int j = 0; j != grid.width; ++j) {
			if (grid.squares[i][j] == NULL)
				cout << "____ ";
			else
				cout << grid.squares[i][j]->species->name[0] 
				     << grid.squares[i][j]->species->name[1]
					 << "_"
					 << directShortName[grid.squares[i][j]->direction]
					 << " ";
		}
		cout << endl;
	}
}

void
simulateCreature(world_t &world, unsigned int creatureID/*, bool verbose*/)
{
	instruction_t instr = getInstruction(world.creatures[creatureID]);
	switch (instr.op) {
		case HOP:
			hop(world, creatureID);
			break;
		case LEFT:
//			left(world, creatureID);
			break;
		case RIGHT:
//			right(world, creatureID);
			break;
		case INFECT:
//			infect(world, creatureID);
			break;
		default:
			;
	}

	instr = getInstruction(world.creatures[creatureID]);
	while (instr.op == IFEMPTY || instr.op == IFWALL || instr.op == IFSAME || 
	  instr.op == IFENEMY || instr.op == GO) {
		switch (instr.op) {
			case IFEMPTY:
//				ifempty(world, creatureID, instr.address);
				break;
			case IFWALL:
//				ifwall(world, creatureID, instr.address);
				break;
			case IFSAME:
//				ifsame(world, creatureID, instr.address);
				break;
			case IFENEMY:
//				ifenemy(world, creatureID, instr.address);
				break;
			case GO:
				go(world, creatureID, instr.address);
				break;
			default:
				;
		}

		instr = getInstruction(world.creatures[creatureID]);
	}
}

opcode_t
findOpcode(const string &operName)
{
	int opcode;
	for (int i = 0; i != 9; ++i)
		if (operName == opName[i])
			opcode = i;
	return (opcode_t)opcode;
}

direction_t
findDir(const string &dir)
{
	int direction;
	for (int i = 0; i != 4; ++i)
		if (dir == directName[i])
			direction = i;
	return (direction_t)direction;
}

species_t *
findSpecies(world_t &world, const string &name)
{
	unsigned int index;
	for (int i = 0; i != world.numSpecies; ++i)
		if (name == world.species[i].name)
			index = i;
	return world.species + index;
}

void
hop(world_t &world, unsigned int creatureID)
{
	creature_t *creature = world.creatures + creatureID;
	point_t orgnlPt = creature->location;
	point_t adjctPt = adjacentPoint(orgnlPt, creature->direction);

	if (adjctPt.r >= 0 && adjctPt.r < world.grid.height && 
			adjctPt.c >= 0 && adjctPt.c < world.grid.width &&
				world.grid.squares[adjctPt.r][adjctPt.c] == NULL) {

		creature->location = adjctPt;
		world.grid.squares[orgnlPt.r][orgnlPt.c] = NULL;
		world.grid.squares[adjctPt.r][adjctPt.c] = creature;

	}

	creature->programID++;
}

void
left(world_t &world, unsigned int creatureID)
{
	creature_t *creature = world.creatures + creatureID;
	creature->direction = leftFrom(creature->direction);
	creature->programID++;
}

void
right(world_t &world, unsigned int creatureID)
{
	creature_t *creature = world.creatures + creatureID;
	creature->direction = rightFrom(creature->direction);
	creature->programID++;
}

void
infect(world_t &world, unsigned int creatureID)
{

}

void
ifempty(world_t &world, unsigned int creatureID, unsigned int address)
{
	
}

void
ifwall(world_t &world, unsigned int creatureID, unsigned int address)
{

}

void
ifsame(world_t &world, unsigned int creatureID, unsigned int address)
{

}

void
ifenemy(world_t &world, unsigned int creatureID, unsigned int address)
{

}

void
go(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	creature->programID = address - 1;
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

