#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int n)
{
	int result = 1;
	if(n < 0)
		throw n;
	for(result = 1; n>0; n--)
		result *= n;

	return result;
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cerr << "Error: missing arguments!" << endl;
        cerr << "Usage: ./exception [num]" << endl;
		return -1;
	}

	int n = atoi(argv[1]);

    cout << factorial(n) << endl;

	return 0;
}
