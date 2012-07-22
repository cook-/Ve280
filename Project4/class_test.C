#include <iostream>

const int ArraySize = 3;

class Class_T
{
	int arr[ArraySize];

public:
	Class_T();
	void printArr();
}

Class_T::Class_T(): arr[ArraySize]({ 1, 2, 3 }) { }

void
printArr()
{
	for (int i = 0; i != ArraySize; ++i)
		std::cout << arr[i] << " ";
	std::cout << endl;
}

int
main()
{
	Class_T test;
	test.printArr();
	return 0;
}
