// test initWorld() and printGrid().

#include "world_type.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool initWorld(world_t &, const string &, const string &);
void printGrid(const grid_t &);
opcode_t findOpcode(const string &);
direction_t findDir(const string &);
species_t *findSpecies(world_t &, const string &);

int
main(int argc, char *argv[])
{
	string speciesFile = argv[1];
	string worldFile = argv[2];

	struct world_t world;
//	cout << "numSpecies: " << world.numSpecies << endl;
//	cout << "name: " << world.species[3].name << endl;
//	ifstream iFile;
//	iFile.open(speciesFile.c_str());
//	cout << "speciesFile succeed?: " << iFile.is_open() << endl;
//	iFile.close();
//	iFile.open(worldFile.c_str());
//	cout << "worldFile succeed?: " << iFile.is_open() << endl;
//	iFile.close();
	initWorld(world, speciesFile, worldFile);
	printGrid(world.grid);

	return 0;
}

bool 
initWorld(world_t &world, const string &speciesFile,
	const string &worldFile)
{
	ifstream iFile;
	istringstream iStream;
	string line;

	iFile.open(speciesFile.c_str());
	cout << speciesFile << " is open?: " << iFile.is_open() << endl;

	string title;
	getline(iFile, title);
	int i = 0;
	while (iFile)
		getline(iFile, world.species[i++].name);	//initialize name.
	world.numSpecies = i - 1;		// initialize numSpecies.
	cout << "numSpecies = " << world.numSpecies << endl;

	iFile.close();

	for (int i = 0; i != world.numSpecies; ++i) {
		iFile.open(world.species[i].name.c_str());
		cout << world.species[i].name << " is open?: " << iFile.is_open() << endl;

		getline(iFile, line);
		
		int j = 0;
		while (!line.empty()) {
			iStream.clear();
			iStream.str(line);

			string operName;
			iStream >> operName;
//			cout << operName << endl;
			world.species[i].program[j].op = findOpcode(operName);	// initialize op.

			if (operName == "ifempty" || operName == "ifenemy" || operName == "ifsame" || operName == "ifwall" || operName == "go")
				iStream >> world.species[i].program[j].address;		// initialize address.

			cout << opName[world.species[i].program[j].op] << " " << world.species[i].program[j].address << endl; 
			j++;
			getline(iFile, line);
		}

		world.species[i].programSize = j;	// initialize programSize.
		cout << "programSize: " << world.species[i].programSize << endl;

		iFile.close();
	}

	iFile.open(worldFile.c_str());
	cout << worldFile << " is open?: " << iFile.is_open() << endl;

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.height;	// initialize height.
	cout << "grid height is: " << world.grid.height << endl;

	getline(iFile, line);
	iStream.clear();
	iStream.str(line);
	iStream >> world.grid.width;	// initialize width.
	cout << "grid width is: " << world.grid.width << endl;

	while (iFile) {
		int i = 0;
		getline(iFile, line);
		iStream.clear();
		iStream.str(line);
		string name, dir;
		iStream >> name >> dir >> world.creatures[i].location.r >> world.creatures[i].location.c;	// initialize r& c.
		world.creatures[i].direction = findDir(dir);	// initialize direction.
		world.creatures[i].species = findSpecies(world, name);	// initialize *species.
		world.creatures[i].programID = 1;	// initialize programID.
		world.grid.squares[world.creatures[i].location.r][world.creatures[i].location.c] = world.creatures + i;	// initialize squares.
		i++;
	}

	iFile.close();

	return true;
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
					 << directShortName[(grid.squares[i][j] -> direction)];
		}
		cout << endl;
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
	for (int i = 0; i != world.numSpecies; i++)
		if (name == world.species[i].name)
			index = i;
	return world.species + index;
}
