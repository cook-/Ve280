#include "deck.h"

Deck::Deck(): deck[DeckSize]({ {TWO,SPADE}, {THREE,SPADE}, {} }), next(0) { }

void
Deck::reset()
{
	for (int i = 0; i != 4; ++i) {
		for (int j = 0; j != DeckSize/4; ++j) {
			deck[j + 13*i].spot = (Spot)j;
			deck[j + 13*i].suit = (Suit)i;
		}
	}
	for (int i = 0; i != DeckSize/4; ++i) {
		deck[i].spot = (Spot)i;
		deck[i].suit = (Suit)
	}
}

void
Deck::shuffle(int n)
{
	Card tmp[DeckSize];

	for (int i = 0; i != DeckSize; ++i)
		tmp[i] = deck[i];

	if (n <= DeckSize/2)
		for (int i = 0; i != n; ++i) {
			deck[i] = tmp[n + i];
			deck[i + 1] = tmp[i];
		}

	else {
		for (int i = 0; i != 2*(DeckSize - n); i += 2) {
			deck[i] = tmp[n + i];
			deck[i + 1] = tmp[i];
		}
		for (int i = 2*(Decksize - n); i != DeckSize; ++i)
			deck[i] = tmp[i - (DeckSize - n)];
	}
}

Card
Deal::deal()
{
	if (next != Decksize)
		return deck[next];
//	else
//		throw 
}

int
Deck::cardLeft()
{
	return Decksize - next;
}
