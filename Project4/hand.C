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
	unsigned int cCount;
	if (c.spot == JACK || c.spot == QUEEN || c.spot == KING)
		cCount = 10;
	else if (c.spot == ACE)
		cCount = 11;
	else
		cCount = c.spot + 2;

	if (!curValue.soft && c.spot != ACE) 
		curValue.count += cCount;

	else if (curValue.soft && c.spot == ACE) {
		if (curValue.count == 21) {
			curValue.count = 12;
			curValue.soft = false;
		}
		else
			curValue.count++;
	}

	else if (curValue.soft && c.spot != ACE){
		if (curValue.count + cCount > 21) {
			curValue.count += (cCount - 10);
			curValue.soft = false;
		}
		else
			curValue.count += cCount;
	}

	else {
		if (curvalue.count + cCount > 21)
			curValue += 1;
		else
			curvalue += 11;
	}
}

HandValue
Hand::handValue() const
{
	return curValue;
}
