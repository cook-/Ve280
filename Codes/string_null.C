// test whether it is illegal to assign NULL to a string.

#include <iostream>
#include <string>
using namespace std;

int
main()
{
	string str = NULL;
	cout << str << endl;
	return 0;
}
