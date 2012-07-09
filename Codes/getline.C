// test getline() for "species"

#include <iostream>
#include <fstream>
using namespace std;

int
main()
{
	ifstream iFile;
	iFile.open("foo");
	string speciesName;
//	getline(iFile, speciesName);
	iFile >> speciesName;
	cout << speciesName << endl;
	iFile.close();
	return 0;
}
