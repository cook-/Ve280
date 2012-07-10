// test initWorld() and printGrid().

#include "world_type.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool initWorld(world_t &, const string &);
void printGrid(const grid_t &);

int
main()
{
	return 0;
}

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
