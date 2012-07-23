#include "hand.h"
#include "card.h"
using namespace std;

Hand::Hand()
{
	curValue.count = 0;
	curValue.soft = false;
}

void
Hand::discardAll()
{
	curValue.count = 0;
	curValue.soft = false;
}

void
Hand::addCard(Card c)
{
	cCount = c.spot + 2;
	if (!curValue.soft && c.spot != ACE) 
		curValue.count += cCount;

	else if (curValue.soft && c.spot == ACE) {
		if (curValue.count == 21) {
			curValue.count = 12;
			curValue.soft = false;
		}
		else
			curValue.count += 1;
	}

	else {
		if (curValue.count > 10) {
			curValue.count += (cCount - 10);
			curValue.soft = false;
		}
		else
			curValue.count += cCount;
	}
}

HandValue
Hand::handValue() const
{
	return curValue;
}
