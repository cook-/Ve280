#include "world_type.h"
#include "simulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

void
initWorld(world_t &world, const string &speciesFile,
	const string &worldFile)
{

	// initialize the struct world_t.

	world.numSpecies = 0;

	for (unsigned int i = 0; i != MAXSPECIES; ++i) {
		world.species[i].name = "";
		world.species[i].programSize = 0;
		for (unsigned int j = 0; j != MAXPROGRAM; ++j) {
			world.species[i].program[j].op = HOP;
			world.species[i].program[j].address = 0;
		}
	}

	world.numCreatures = 0;

	for (unsigned int i = 0; i != MAXCREATURES; ++i) {
		world.creatures[i].location.r = 0;
		world.creatures[i].location.c = 0;
		world.creatures[i].direction = EAST;
		world.creatures[i].species = NULL;
		world.creatures[i].programID = 0;
	}

	world.grid.height = 0;
	world.grid.width = 0;

	for (unsigned int i = 0; i != MAXHEIGHT; ++i)
		for (unsigned int j = 0; j != MAXWIDTH; ++j)
			world.grid.squares[i][j] = NULL;


	// assign file data to  numSpecies and species[].

	ifstream iFile;
	istringstream iStream;
	string line;

	iFile.open(speciesFile.c_str());
	try {
		if (!iFile) throw speciesFile;
	}
	catch (string &fileName) {
		cout << "Error: Cannot open file " << fileName << endl;
	}

	getline(iFile, line);
	getline(iFile, line);
	unsigned int i = 0;
	while (!line.empty()) {
		iStream.clear();
		iStream.str(line);
		try {
			if (i == MAXSPECIES) throw MAXSPECIES;
		}
		catch (unsigned int &maxSpecies) {
			cout << "Error: Too many species!\n" 
				 << "Maximal number of species is " << maxSpecies << "." 
				 << endl;
			throw;
		}
		iStream >> world.species[i].name;
		getline(iFile, line);
		i++;
	}
	world.numSpecies = i;

	iFile.close();

	for (unsigned int i = 0; i != world.numSpecies; ++i) {

		string destFile = "creatures/" + world.species[i].name;
		iFile.open(destFile.c_str());
		try {
			if (!iFile) throw world.species[i].name;
		}
		catch (string &fileName){
			cout << "Error: Cannot open file " << fileName << "!" << endl;
			throw;
		}

		unsigned int j = 0;
		getline(iFile, line);
		while (!line.empty()) {
			iStream.clear();
			iStream.str(line);
			try {
				if (j == MAXPROGRAM) throw MAXPROGRAM;
			}
			catch (unsigned int &maxProgram) {
				cout << "Error: Too many instructions for species " 
					 << world.species[i].name << "!\n" 
					 << "Maximal number of instructions is "
					 << maxProgram << "." << endl;
				throw;
			}

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
	try {
		if (!iFile) throw worldFile;
	}
	catch (string &fileName) {
		cout << "Error: Cannot open file " << fileName << "!" << endl;
		throw;
	}

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	unsigned int height;
	iStream >> height;
	try {
		if (height < 0 || height > MAXHEIGHT) throw MAXHEIGHT;
	}
	catch (unsigned int &maxHeight) {
		cout << "Error: The grid height is illegal!" << endl;
		throw;
	}
	world.grid.height = height;

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	unsigned int width;
	iStream >> width;
	try {
		if (width < 0 || width > MAXWIDTH) throw MAXWIDTH;
	}
	catch (unsigned int &maxWidth) {
		cout << "Error: The grid width is illegal!" << endl;
		throw;
	}
	world.grid.width = width;
	
	getline(iFile, line);
	i = 0;
	while (!line.empty()) {
		iStream.clear();
		iStream.str(line);
		try {
			if (i == MAXCREATURES) throw MAXCREATURES;
		}
		catch (unsigned int &maxCreatures) {
			cout << "Error: Too many creatures!\n" 
				 << "Maximal number of creatures is "
				 << maxCreatures << "." << endl;
			throw;
		}

		string name, dir;
		unsigned int row, col;
		iStream >> name >> dir >> row >> col;

		try {
			if (row < 0 || row >= height || col < 0 || col >= width) 
				throw -1;
		}
		catch (int &e) {
			cout << "Error: Creature (" 
				 << name << " " << dir << " " << row << " " << col 
				 << ") is out of bound!\n" 
				 << "The grid size is " 
				 << world.grid.height << "-by-" << world.grid.width << "." 
				 << endl;
			throw;
		}

		world.creatures[i].direction = findDir(dir);
		world.creatures[i].species = findSpecies(world, name);
		world.creatures[i].location.r = row; 
		world.creatures[i].location.c = col;
		world.creatures[i].programID = 0;
		world.grid.squares[world.creatures[i].location.r]\
						[world.creatures[i].location.c] = world.creatures + i;

		getline(iFile, line);
		i++;
	}
	world.numCreatures = i;
	
	try {
		for (unsigned int i = 0; i != world.numCreatures-1; ++i) {
			for (unsigned int j = i+1; j != world.numCreatures; ++j) {
				if (world.creatures[i].location.r == 
						world.creatures[j].location.r && 
					  world.creatures[i].location.c == 
					    	world.creatures[j].location.c) {
					unsigned int pair[] = {i, j};
				  	throw pair;
				}
			}
		}
	}
	catch (int *e) {
		int i = *e;
		int j = *(e + 1);
		cout << "Error: Creature (" 
			 << world.creatures[j].species->name << " " 
			 << directName[world.creatures[j].direction] << " "  
			 << world.creatures[j].location.r << " " 
			 << world.creatures[j].location.c 
			 << ") overlaps with creature (" 
			 << world.creatures[i].species->name << " " 
			 << directName[world.creatures[i].direction] << " "  
			 << world.creatures[i].location.r << " " 
			 << world.creatures[i].location.c 
			 << ")!" << endl;
		throw;
	}

	iFile.close();
}

void
simulateCreature(world_t &world, unsigned int creatureID, bool verbose)
{
	instruction_t instr = getInstruction(world.creatures[creatureID]);
	creature_t *creature = world.creatures + creatureID;

	cout << "Creature (" 
		 << creature->species->name << " "
		 << directName[creature->direction] << " "
		 << creature->location.r << " "
		 << creature->location.c
		 << ") takes action:";

	while (instr.op == IFEMPTY || instr.op == IFWALL || instr.op == IFSAME || 
	  instr.op == IFENEMY || instr.op == GO) {

	  	if (verbose) {
			cout << endl << "Instruction " 
				 << creature->programID + 1 << ": " 
				 << opName[instr.op] << " " 
				 << instr.address;
		}

		switch (instr.op) {
			case IFEMPTY:
				ifempty(world, creatureID, instr.address);
				break;
			case IFWALL:
				ifwall(world, creatureID, instr.address);
				break;
			case IFSAME:
				ifsame(world, creatureID, instr.address);
				break;
			case IFENEMY:
				ifenemy(world, creatureID, instr.address);
				break;
			case GO:
				go(world, creatureID, instr.address);
				break;
			default:
				;
		}
		instr = getInstruction(world.creatures[creatureID]);
	}

  	if (verbose) {
		cout << endl << "Instruction " 
			 << creature->programID + 1 << ": " 
			 << opName[instr.op] << endl;
	}
	else {
		cout << " " << opName[instr.op] << endl;
	}

	switch (instr.op) {
		case HOP:
			hop(world, creatureID);
			break;
		case LEFT:
			left(world, creatureID);
			break;
		case RIGHT:
			right(world, creatureID);
			break;
		case INFECT:
			infect(world, creatureID);
			break;
		default:
			;
	}

	if (verbose || creatureID == world.numCreatures - 1)
		printGrid(world.grid);
}

void 
printGrid(const grid_t &grid)
{
	for (unsigned int i = 0; i != grid.height; ++i) {
		for (unsigned int j = 0; j != grid.width; ++j) {
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

opcode_t
findOpcode(const string &operName)
{
	int opIndex;
	bool isFound = false;
	for (int i = 0; i != 9; ++i)
		if (operName == opName[i]) {
			opIndex = i;
			isFound = !isFound;
		}

	try {
		if (!isFound) throw operName;
	}
	catch (string str) {
		cout << "Error: Instruction " << str << " is not recognized!" << endl;
		throw;
	}

	return (opcode_t)opIndex;
}

direction_t
findDir(const string &dir)
{
	int dirIndex;
	bool isFound = false;
	for (int i = 0; i != 4; ++i)
		if (dir == directName[i]) {
			dirIndex = i;
			isFound = !isFound;
		}

	try {
		if (!isFound) throw dir;
	}
	catch (string str) {
		cout << "Error: Direction " << dir << " is not recognized!" << endl;
		throw;
	}

	return (direction_t)dirIndex;
}

species_t *
findSpecies(world_t &world, const string &name)
{
	int speciesIndex;
	bool isFound = false;
	for (unsigned int i = 0; i != world.numSpecies; ++i)
		if (name == world.species[i].name) {
			speciesIndex = i;
			isFound = !isFound;
		}

	try {
		if (!isFound) throw name;
	}
	catch (string str){
		cout << "Error: Species " << str << " not found!" << endl;
		throw;
	}

	return world.species + speciesIndex;
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
			pt.r++;
			break;
		case (WEST):
			pt.c--;
			break;
		case (NORTH):
			pt.r--;
			break;
		default:
			;
	}
	return pt;
}

direction_t 
leftFrom(direction_t dir)
{
	int direction = (int)dir;
	if (dir == EAST)
		direction = 3;
	else
		direction--;
	return (direction_t)direction;
}

direction_t 
rightFrom(direction_t dir)
{
	int direction = (int)dir;
	if (dir == NORTH)
		direction = 0;
	else
		direction++;
	return (direction_t)direction;
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

void
hop(world_t &world, unsigned int creatureID)
{
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	creature_t *adjctCreature = getCreature(world.grid, adjctPt);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row >= 0 && row < world.grid.height && 
			col >= 0 && col < world.grid.width &&
				adjctCreature == NULL) {

		world.grid.squares[creature->location.r][creature->location.c] = NULL;
		world.grid.squares[row][col] = creature;
		creature->location = adjctPt;
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
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	creature_t *adjctCreature = getCreature(world.grid, adjctPt);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row >= 0 && row < world.grid.height && 
		  col >= 0 && col < world.grid.width && 
			adjctCreature != NULL && 
			  adjctCreature->species != creature->species) {

		adjctCreature->species = creature->species;
		adjctCreature->programID = 0;
	}

	creature->programID++;
}

void
ifempty(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	creature_t *adjctCreature = getCreature(world.grid, adjctPt);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row >= 0 && row < world.grid.height && 
		  col >= 0 && col < world.grid.width && 
			adjctCreature == NULL) 

		creature->programID = address - 1;
	else
		creature->programID++;
}

void
ifwall(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row < 0 || row >= world.grid.height || 
		  col < 0 || col >= world.grid.width) 

		creature->programID = address - 1;
	else
		creature->programID++;
}

void
ifsame(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	creature_t *adjctCreature = getCreature(world.grid, adjctPt);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row >= 0 && row < world.grid.height && 
		  col >= 0 && col < world.grid.width && 
			adjctCreature != NULL && 
			  adjctCreature->species == creature->species)

		creature->programID = address - 1;
	else
		creature->programID++;
}

void
ifenemy(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	point_t adjctPt = adjacentPoint(creature->location, creature->direction);
	creature_t *adjctCreature = getCreature(world.grid, adjctPt);
	unsigned int row = adjctPt.r;
	unsigned int col = adjctPt.c;

	if (row >= 0 && row < world.grid.height && 
		  col >= 0 && col < world.grid.width && 
			adjctCreature != NULL && 
			  adjctCreature->species != creature->species)

		creature->programID = address - 1;
	else
		creature->programID++;
}

void
go(world_t &world, unsigned int creatureID, unsigned int address)
{
	creature_t *creature = world.creatures + creatureID;
	creature->programID = address - 1;
}

