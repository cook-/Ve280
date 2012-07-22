#include <iostream>

using namespace std;
const int size = 10;

int main()
{
	int array[size];
	int i;
	for(i = 0; i < size; i++)
		array[i] = i;

	for(i = 0; i < size; i++)
		cout << array[i] << " ";

	cout << endl;

    return 0;
}
