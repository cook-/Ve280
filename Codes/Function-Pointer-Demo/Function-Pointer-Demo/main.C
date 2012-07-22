#include <iostream>
#include "list.h"
#include "compare.h"

using namespace std;

int main(int argc, char* argv[])
{
	list_t list = list_make();
	list = list_make(2, list);
	list = list_make(4, list);
	list = list_make(8, list);
	list = list_make(7, list);
	list = list_make(3, list);
	cout << "The list is " << flush;
	list_print(list);
	cout << endl;
	cout << "The smallest element is " << smallest(list) << endl;
	cout << "The largest element is " << largest(list) << endl;
	return 0;
}
