#include "player.h"
#include "hand.h"
using namespace std;

class simplePlayer : public Player {
	unsigned int bankroll;
	Hand player;
 public:
 	simplePlayer();
	int bet(unsigned int bankroll, unsigned int minimum);
	bool draw(Card dealer, const Hand &player);
};

simplePlayer::simplePlayer()
{
	bankroll = 0;
	player.count = 0;
	player.soft = false;
}

int
simplePlayer::bet(unsigned int bankroll, unsigned int minimum)
{
	return minimum;
}

bool
simplePlayer::draw(Card dealer, const Hand &player)
{
	if (!player.curValue.soft) {
		if (player.curValue.count <= 11)
			return true;

		else if (player.curValue.count == 12)
			return (dealer.spot - 2) >= 4
					  && (dealer.spot - 2) <= 6 ? false : true;

		else if (player.curValue.count >= 13
				   && player.curValue.count <= 16)
			return (dealer.spot - 2) >= 2
					  && (dealer.spot - 2) <= 6 ? false : true;

		else
			return false;
	}

	else {
		if (player.curValue.count <= 17)
			return true;
		
		else if (player.curValue.count == 18)
			return (dealer.spot - 2) == 2
					 || (dealer.spot - 2) == 7
					 || (dealer.sopt - 2) == 8 ? false : true;

		else
			return false;
	}
}

class countingPlayer : public simplePlayer {
	unsigned int bankroll;
	Hand player;
	int count;
 public:
 	countingPlayer();
	int bet(unsigned int bankroll, unsigned int minimum);
	void expose(Card c);
	void shuffle();
};

countingPlayer::countingPlayer
{
	bankroll = 0;
	player.count = 0;
	player.soft = false;
	count = 0;
}

int
countingPlayer::bet(unsigned int bankroll, unsigned int minimum)
{
	return (count >= 2 && bankroll >= 2*minimum) ? 
										2*minimum : minimum;
}

void
countingPlayer::expose(Card c)
{
	if ((c.spot + 2) >= 10)
		count++;
	else
		count--;
}

void
countingPlayer::shuffle()
{
	count = 0;
}

static simplePlayer sPlayer;
static countingPlayer cPlayer;

extern Player *get_Simple()
{
	return &sPlayer;
}

extern Player *get_Counting()
{
	return &cPlayer;
}
