#include "dlist.h"
#include "dlist.C"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Call {
	unsigned int t;
	string name;
	string status;
	unsigned int duration;
};

const unsigned int statusNum = 4;
const string Status[] = { "platinum", "gold", "silver", "regular" };

bool allEmpty(Dlist<Call> *Calls[]);

int
main()
{
	unsigned int eventNum;
	cin >> eventNum;

	Dlist<Call> platinum, pBuffer;
	Dlist<Call> gold, gBuffer;
	Dlist<Call> silver, sBuffer;
	Dlist<Call> regular, rBuffer;

	Dlist<Call> *Calls[] = { &platinum, &gold, &silver, &regular };
	Dlist<Call> *Buffers[] = { &pBuffer, &gBuffer, &sBuffer, &rBuffer };

	unsigned int t;
	string name;
	string status;
	unsigned int duration;
	Call *newCall = 0;

	for (unsigned int j = 0; j != eventNum; ++j) {
		cin >> t >> name >> status >> duration;
		for (unsigned int i = 0; i != statusNum; ++i) {
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

	unsigned int busyTime = 0;
	unsigned int tick = 0;
	Call *call = 0;
	
	while (!allEmpty(Calls) || !allEmpty(Buffers) || (busyTime != 0)) {
		cout << "Starting tick #" << tick << endl;

		for (unsigned int i = 0; i != statusNum; ++i) {

			while (!Calls[i]->isEmpty()) {

				call = Calls[i]->removeFront();
				if (call->t == tick) {
					cout << "Call from " << call->name << " a "
						 << call->status << " member " << endl;
					Buffers[i]->insertBack(call);
				}
				else {
					Calls[i]->insertFront(call);
					break;
				}

			}
		}

		if (busyTime == 0) {
			for (unsigned int i = 0; i != statusNum; ++i)

				if (!Buffers[i]->isEmpty()) {
					call = Buffers[i]->removeFront();
					cout << "Answering call from " << call->name << endl;
					busyTime = call->duration;
					delete call;
					break;
				}

		}

		busyTime = (busyTime == 0) ? 0 : (busyTime - 1);
		tick++;
	}

	cout << "Starting tick #" << tick << endl;

	return 0;
}

bool
allEmpty(Dlist<Call> *Calls[])
{
	bool allEmpty = true;

	for (unsigned int i = 0; i != statusNum; ++i)
		allEmpty = allEmpty && Calls[i]->isEmpty();

	return allEmpty;
}


