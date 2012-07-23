#include "deck.h"
#include "card.h"
using namespace std;

Deck::Deck()
{
	for (int i = 0; i != 4; ++i)
		for (int j = 0; j != DeckSize/4; ++j) {
			deck[j + 13*i].spot = (Spot)j;
			deck[j + 13*i].suit = (Suit)i;
		}

	next = 0;
}

void
Deck::reset()
{
	for (int i = 0; i != 4; ++i)
		for (int j = 0; j != DeckSize/4; ++j) {
			deck[j + 13*i].spot = (Spot)j;
			deck[j + 13*i].suit = (Suit)i;
		}

//	next = 0;
}

void
Deck::shuffle(int n)
{
	Card tmp[DeckSize];

	for (int i = 0; i != DeckSize; ++i)
		tmp[i] = deck[i];

	if (n <= DeckSize/2)
		for (int i = 0; i != n; ++i) {
			deck[2*i] = tmp[n + i];
			deck[2*i + 1] = tmp[i];
		}

	else {
		for (int i = 0; i != DeckSize - n; ++i) {
			deck[2*i] = tmp[n + i];
			deck[2*i + 1] = tmp[i];
		}
		for (int i = DeckSize - n; i != n; ++i)
			deck[DeckSize - n + i] = tmp[i];
	}
}

Card
Deck::deal()
{
	if (next != DeckSize)
		return deck[next++];
	else {
		DeckEmpty emptyDeck;
		throw emptyDeck; 
	}
}

int
Deck::cardsLeft()
{
	return DeckSize - next;
}
