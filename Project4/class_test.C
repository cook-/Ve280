#include <iostream>
using namespace std;

const int ArraySize = 3;

class Class_T
{
	int arr[ArraySize];

public:
	Class_T();
	void printArr();
};

Class_T::Class_T(): arr[ArraySize]({ 1, 2, 3 }) { }

void
printArr()
{
	for (int i = 0; i != ArraySize; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int
main()
{
	Class_T test;
	test.printArr();
	return 0;
}
