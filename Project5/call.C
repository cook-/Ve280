#include "dlist.h"
#include "dlist.C"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Call {
	int t;
	string name;
	string status;
	int duration;
};

const string Status[] = { "platinum", "gold", "silver", "regular" };

int
main()
{
	int eventNum;
	cin >> eventNum;

	Dlist<Call> platinum;
	Dlist<Call> gold;
	Dlist<Call> silver;
	Dlist<Call> regular;

	Dlist<Call> *Calls[] = { &platinum, &gold, &silver, &regular };

	int t;
	string name;
	string status;
	int duration;
	Call *newCall = 0;

	while (cin) {
		cin >> t >> name >> status >> duration;
		for (int i = 0; i != 4; ++i) {
			if (status == Status[i]) {
				newCall = new Call;
				newCall->t = t;
				newCall->name = name;
				newCall->status = status;
				newCall->duration = duration;
				Calls[i]->insertBack(newCall);
			}
		}
	}

	return 0;
}
