#include <iostream>
#include <cstdlib>
using namespace std;

int fact_helper(int n, int result)
{
	if(n < 0)
		throw n;
	if(n == 0)
		return result;
	else
		return fact_helper(n-1, n*result);
}

int factorial(int n)
{
	return fact_helper(n,1);
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
	try
	{
        cout << factorial(n) << endl;
	}
	catch(int v)
	{
		cerr << "Error: negative input: " << v << endl;  
	}

	return 0;
}
