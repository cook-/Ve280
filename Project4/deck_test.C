#include "deck.h"

int
main()
{
	Deck testDeck;

	testDeck.reset();
	testDeck.shuffle(3);

	testDeck.reset();
	testDeck.shuffle(50);

	return 0;
}
