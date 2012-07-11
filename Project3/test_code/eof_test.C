#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int
main()
{
	ifstream iFile;
	iFile.open("eof_test");
	int i = 0;
	string line;
	while (iFile) {
		getline(iFile, line);
		i++;
	}
	cout << "There are " << i << " lines in the file." << endl;

	return 0;
}
