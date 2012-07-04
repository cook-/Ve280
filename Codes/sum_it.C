// calculate the sum of input arguments.

#include <iostream>

int
main(int argc, char *argv[])
{
	int sum = 0;
	for (int i = 1; i != argc; ++i){
		sum += atio(argv[i]);
	}
	cout << "sum is " << sum;
	return 0;
}
