#include "player.h"
#include "rand.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

int
main(int argc, char *argv[])
{
	unsigned int bankroll = atoi(argv[1]);
	unsigned int hands = atoi(argv[2]);
	string feature = argv[3];

	Deck deck;
	Hand hand;
	Player *player = (feature == "simple") ? get_Simple() : get_Counting;

	cout << "Shuffling the deck\n";
	for (int i = 0; i != 7; ++i) {
		deck.shuffle(get_cut());
		player->shuffled();
	}

	unsigned int thishand = 1;
	unsigned int minimum = 5;
	unsigned int wager;
	Card nextCard;
	Card dealer;
	Card holeCard;
	HandValue playerValue;

	for (int i = 0; i != hands; ++i) {
		cout << "Hand " << thishand << " bankroll " << bankroll << endl;

		if ((num = deck.cardsLeft()) < 20) {
			deck.shuffle(get_cut());
			player->shuffled();
		}

		wager = player.bet(bankroll, minimum);
		cout << "Player bets " << wager << endl;

		nextCard = deck.deal();
		player.expose(nextCard);
		hand.addCard(nextCard);
		cout << "Player dealt " << SpotNames[nextCard.spot] 
			 << " of " << SuitNames[nextCard.suit];

		nextCard = deck.deal();
		player.expose(nextCard);
		dealer = nextCard;
		cout << "Dealer dealt " << SpotNames[nextCard.spot]
			 << " of " << SuitNames[nextCard.suit];

		nextCard = deck.deal();
		player.expose(nextCard);
		hand.addCard(nextCard);
		cout << "Player dealt " << SpotNames[nextCard.spot]
			 << " of " << SuitNames[nextCard.suit];

		nextCard = deck.deal();
		holeCard = nextCard;

		playerValue = hand.handValue();
		if (playerValue.count == 21) {
			bankroll += 3*wager/2
			cout << "Player dealt natural 21\n";
		}
		
		while (draw(dealer, player)) {
			
		}
	thishand++;
	}



	return 0;
}
