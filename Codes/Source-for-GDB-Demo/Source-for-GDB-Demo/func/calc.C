#include "func.h"
#include <iostream>

using namespace std;

int main()
{
	int n, result;
	cout << "Input an integer: ";
	cin >> n;

	result = factorial(n);
	cout << n << "! = " << result << endl;

    return 0;
}
