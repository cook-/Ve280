#include "card.h"
#include "hand.h"

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
	if (!soft && c.spot != ACE) 
		curValue += ((int)c.spot + 2);

	else if (soft && c.spot == ACE) {
		if (curValue.count == 21) {
			curValue.count = 12;
			curValue.soft = false;
		}
		else
			curValue.count += 1;
	}

	else {
		if (curValue > 10) {
			curValue.count += (((int)c.spot + 2) - 10);
			curValue.soft = false;
		}
		else
			curValue += ((int)c.spot + 2);
	}
}

HandValue
Hand::handValue() const
{
	return curValue;
}
