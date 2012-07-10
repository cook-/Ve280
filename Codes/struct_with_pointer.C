// test a struct with a pointer.

#include <iostream>
#include <string>
using namespace std;

struct species_t
{
	string name;
	int size;	
};

struct creature_t
{
	int location;
	species_t *species;
};

int
main()
{
	struct species_t sp;
	struct creature_t cr;
	cr.species->name = "food";
	cout << sp.name << endl;
	return 0;
}
