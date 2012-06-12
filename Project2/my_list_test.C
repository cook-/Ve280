#include <iostream>
#include "recursive.h"
#include "p2.h"
using namespace std;

int add(int x, int y)
{
	return x + y;
}

bool odd(int a)
{
	return a % 2;
}

int main()
{
	int i;
	list_t listA;
	list_t listB;
	listA = list_make();
	listB = list_make();
	for (i = 5; i != 0; --i) {
		listA = list_make(i, listA);
		listB = list_make(i+10, listB);
	}
	list_print(listA);
	cout << endl;
	list_print(listB);
	cout << endl;
	cout << "size of listA: " << size(listA) << endl;
	cout << "size of listB: " << size(listB) << endl;
	cout << "3rd element of listA: " << getNth(listA, 3) << endl;
	cout << "product of elements in listA: " << product(listA) << endl;
	cout << "sum of elements in listA: " << sum(listA) << endl;
	cout << "sum of elements in listB: " << accumulate(listB, add, 0) << endl;
	list_print(reverse(listA));
	cout << endl;
	list_print(reverse(listB));
	cout << endl;
	list_print(append(listA, listB));
	cout << endl;
	list_print(filter_odd(listA));
	cout << endl;
	list_print(filter_even(listB));
	cout << endl;
	list_print(filter(listA, odd));
	cout << endl;
	list_print(insert_list(listA, listB, 3));
	cout << endl;
	list_print(removeNth(listA, 3));
	cout << endl;
	list_print(chop(listA, 3));
	cout << endl;
	return 0;
}
