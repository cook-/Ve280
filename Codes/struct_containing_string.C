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
	}

	world_t world{ 1, "abc"};
	cout << world.ival << " " << world.str << endl;

	return 0;
}
