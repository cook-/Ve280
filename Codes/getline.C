// test getline() for "species"

#include <iostream>
#include <fstream>
using namespace std;

int
main()
{
	ifstream iFile;
	iFile.open("species");
	string speciesName;
	getline(iFile, speciesName);
	cout << speciesName << endl;
	iFile.close();
	return 0;
}
