// test enum type.

#include <iostream>
#include <string>
using namespace std;

enum direction_t { EAST, SOUTH, WEST, NORTH };

const string directName[] = { "east", "south", "west", "north" };

int
main()
{
	string dir = "west";
	int offset;
	for (int i = 0; i != 4; ++i)
		if (dir == directName[i])
			offset = i;
	direction_t result = EAST;
	result += offset;

	return 0;
}
