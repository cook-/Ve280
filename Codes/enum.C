// test enum type.

enum direction_t { EAST, SOUTH, WEST, NORTH };

const string directName[] = { "east", "south", "west", "north" };

#include <iostream>
using namespace std;

int
main()
{
	string dir = west;
	int offset;
	for (int i = 0; i != 4; ++i)
		if (dir == directName[i])
			offset = i;
	direction_t result;
	result = EAST + offset;
}
