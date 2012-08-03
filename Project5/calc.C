#include "dlist.h"
#include "dlist.C"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

int
main()
{
	Dlist<int> ilist;
	string cmd;
	cin >> cmd;
	if (cmd.size() == 1)
		cout << "ok" << endl;


	return 0;
}
