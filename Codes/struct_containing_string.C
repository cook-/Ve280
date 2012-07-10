// initialize the string in a struct.

#include <iostream>
#include <string>
using namespace std;

int
main()
{
	struct world_t
	{
		int ival;
		string str;
	};

	world_t world;
	cout << world.ival << " " << world.str << endl;

	return 0;
}
