// test a struct with a pointer.

#include <iostream>
#include <string>
using namespace std;

struct species_t
{
	string name;
	int size;	
}

struct creature_t
{
	int location;
	species_t *species;
}

int
main()
{
	struct species_t sp{ "food", 10 };
	struct species_t cr{ 30, &sp};
	return 0;
}
