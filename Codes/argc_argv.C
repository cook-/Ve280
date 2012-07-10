// test arguments in command line.

#include <iostream>
#include <string>
using namespace std;

int
main(int argc, char *argv[])
{
	string str1, str2;
	str1 = argv[1];
	str2 = argv[2];
	cout << str1 << " " << str2 << endl;
	return 0;
}
