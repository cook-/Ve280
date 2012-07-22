#include "deck.h"

int
main()
{
	Deck testDeck;

	testDeck.reset();
	testDeck.shuffle(26);

	testDeck.reset();
	testDeck.shuffle(52);

	testDeck.reset();
	testDeck.shuffle(0);

}
