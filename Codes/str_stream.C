// extract input from a string.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int
main()
{
	string line = "42 3.14";
	istringstream iStream;
	int foo;
	double bar;
	iStream.str(line);
	iStream >> foo >> bar;
	cout << "foo = " << foo << endl;
	cout << "bar = " << bar << endl;
	return 0;
}
