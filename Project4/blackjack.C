#include "card.h"
#include "deck.h"
#include "hand.h"
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
	Hand playerHand, dealerHand;
	Player *player;

	if (feature == "simple")
		player = get_Simple();
	else if (feature == "counting")
		player = get_Counting();
	else
		return -1;

	cout << "Shuffling the deck\n";
	int cut;
	for (int i = 0; i != 7; ++i) {
		cut = get_cut();
		deck.shuffle(cut);
		cout << "cut at " << cut << endl;
	}

	player->shuffled();

	unsigned int minimum = 5;
	unsigned int wager = player->bet(bankroll, minimum);
	Card nextCard;
	Card dealer;
	Card holeCard;
	HandValue playerValue, dealerValue;

	unsigned int i;
	for (i = 0; i != hands && bankroll >= wager; ++i) {
		cout << "Hand " << i + 1 << " bankroll " << bankroll << endl;

		if (deck.cardsLeft() < 20) {
			deck.reset();
			cout << "Shuffling the deck\n";
			for (int i = 0; i != 7; ++i) {
				cut = get_cut();
				deck.shuffle(get_cut());
				cout << "cut at " << cut << endl;
			}
			player->shuffled();
		}

		cout << "Player bets " << wager << endl;

		try
			nextCard = deck.deal();
		catch (DeckEmpty)
			return 0;
		player->expose(nextCard);
		playerHand.addCard(nextCard);
		cout << "Player dealt " << SpotNames[nextCard.spot] 
			 << " of " << SuitNames[nextCard.suit] << endl;

		nextCard = deck.deal();
		player->expose(nextCard);
		dealer = nextCard;
		dealerHand.addCard(nextCard);
		cout << "Dealer dealt " << SpotNames[nextCard.spot]
			 << " of " << SuitNames[nextCard.suit] << endl;

		nextCard = deck.deal();
		player->expose(nextCard);
		playerHand.addCard(nextCard);
		cout << "Player dealt " << SpotNames[nextCard.spot]
			 << " of " << SuitNames[nextCard.suit] << endl;

		nextCard = deck.deal();
		holeCard = nextCard;
		dealerHand.addCard(nextCard);

		playerValue = playerHand.handValue();
		if (playerValue.count == 21) {
			bankroll += 3*wager/2;
			cout << "Player dealt natural 21\n";
		}
		
		while (player->draw(dealer, playerHand) && playerValue.count <= 21) {
			nextCard = deck.deal();
			player->expose(nextCard);
			playerHand.addCard(nextCard);
			playerValue = playerHand.handValue();
			cout << "Player dealt " << SpotNames[nextCard.spot]
				 << " of " << SuitNames[nextCard.suit] << endl;
		}
		cout << "Player's total is " << playerValue.count << endl;

		if (playerValue.count > 21) {
			cout << "Player busts\n";
			bankroll -= wager;
		}
		else {
			cout << "Dealer's hole card is " << SpotNames[holeCard.spot]
				 << " of " << SuitNames[holeCard.suit] << endl;
			player->expose(holeCard);
			dealerValue = dealerHand.handValue();
			while (dealerValue.count < 17) {
				nextCard = deck.deal();
				player->expose(nextCard);
				dealerHand.addCard(nextCard);
				dealerValue = dealerHand.handValue();
				cout << "Dealer dealt " << SpotNames[nextCard.spot]
					 << " of " << SuitNames[nextCard.suit] << endl;
			}
			cout << "Dealer's total is " << dealerValue.count << endl;

			if (dealerValue.count > 21) {
				cout << "Dealer busts\n";
				bankroll += wager;
			}
			else if (dealerValue.count > playerValue.count) {
				cout << "Dealer wins\n";
				bankroll -= wager;
			}
			else if (dealerValue.count < playerValue.count) {
				cout << "Player wins\n";
				bankroll += wager;
			}
			else
				;
		}

		wager = player->bet(bankroll, minimum);
		playerHand.discardAll();
		dealerHand.discardAll();
	}

	cout << "Player has " << bankroll
		 << " after " << i << " hands\n";

	return 0;
}
