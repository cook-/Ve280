// calculate the sum of input arguments.

#include <iostream>
#include <cstdlib>
using namespace std;

int
main(int argc, char *argv[])
{
	int sum = 0;
	for (int i = 1; i != argc; ++i){
		sum += atoi(argv[i]);
	}
	cout << "sum is " << sum << endl;
	return 0;
}
