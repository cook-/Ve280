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
	while (!iFile.eof()) {
		i++;
	}
	cout << "There are " << i << " lines in th file." << endl;

	return 0;
}
