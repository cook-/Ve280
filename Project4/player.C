#include "player.h"
#include "hand.h"
using namespace std;

class simplePlayer : public Player {
	unsigned int bankroll;
 public:
 	simplePlayer();
	int bet(unsigned int bankroll, unsigned int minimum);
	bool draw(Card dealer, const Hand &player);
	void expose(Card c);
	void shuffled();
};

simplePlayer::simplePlayer(): bankroll(0) { }

int
simplePlayer::bet(unsigned int bankroll, unsigned int minimum)
{
	return minimum;
}

bool
simplePlayer::draw(Card dealer, const Hand &player)
{
	HandValue value = player.handValue();
	unsigned int dealerCount = dealer.spot - 2;
	if (!value.soft) {
		if (value.count <= 11)
			return true;
		else if (value.count == 12)
			return dealerCount >= 4 && dealerCount <= 6 ? false : true;
		else if (value.count >= 13 && value.count <= 16)
			return dealerCount >= 2 && dealerCount <= 6 ? false : true;
		else
			return false;
	}
	else {
		if (value.count <= 17)
			return true;	
		else if (value.count == 18)
			return dealerCount == 2 || dealerCount == 7 
				|| dealerCount == 8 ? false : true;
		else
			return false;
	}
}

void
simplePlayer::expose(Card c) { }

void
simplePlayer::shuffled() { }

class countingPlayer : public simplePlayer {
	unsigned int bankroll;
	int cnt;
 public:
 	countingPlayer();
	int bet(unsigned int bankroll, unsigned int minimum);
	void expose(Card c);
	void shuffled();
};

countingPlayer::countingPlayer(): bankroll(0), cnt(0) { }

int
countingPlayer::bet(unsigned int bankroll, unsigned int minimum)
{
	return (cnt >= 2 && bankroll >= 2*minimum) ? 
										2*minimum : minimum;
}

void
countingPlayer::expose(Card c)
{
	unsigned int cCount = c.spot + 2;
	if (cCount >= 10)
		cnt++;
	else
		cnt--;
}

void
countingPlayer::shuffled()
{
	cnt = 0;
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
