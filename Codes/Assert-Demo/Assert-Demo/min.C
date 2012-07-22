#include <iostream>
//#define NDEBUG
#include <cassert>
using namespace std;

int min(int a, int b)
// INCORRECT min function. It actually returns the max of a and b
{
	if(a < b)
		return a-1;
	else
		return b-1;
}

int main(int argc, char *argv[])
{
	int a, b;
	int smaller;
	cout << "Please input the first number: " << flush;
	cin >> a;
	cout << "Please input the second number: " << flush;
	cin >> b;
	smaller = min(a, b);
	assert((smaller == a && smaller <= b)||(smaller == b && smaller <=a));
    return 0;
}
