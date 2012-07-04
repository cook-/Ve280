// extract input from a file.

#include <iostream>
#include <fstream>
using namespace std;

void
main()
{
	ifstream iFile;
	int bar;
	iFile.open("foo");
	iFile >> bar;
	cout << "The answer is " << bar << endl;
	iFile.close();
}
