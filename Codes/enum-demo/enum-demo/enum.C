#include <iostream>
#include <cassert>
#include <string>
using namespace std;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

const string suitname[] = {"clubs", "diamonds", "hearts", "spades"};

bool isRed(enum Suit s)
{
	switch (s)
    {
		case DIAMONDS: 
		case HEARTS:
			return true;
			break;
		case CLUBS:
		case SPADES:
			return false;
			break;
		default:
			assert(0);
			break;
	}
}

int main(int argc, char *argv[])
{
    enum Suit s = DIAMONDS;
    if(isRed(s))
        cout << "Suit " << suitname[s] << " is red!" << endl;
    else
        cout << "Suit " << suitname[s] << " is not red!" << endl;
    return 0;
}
