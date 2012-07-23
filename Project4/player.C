#include "player.h"
#include "hand.h"
using namespace std;

class simplePlayer : public Player {


 public:
	int bet(unsigned int bankroll, unsigned int minimum);
	bool draw(Card dealer, const Hand &player);
	void expose(Card c);
	void shuffle();
};

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

void
simplePlayer::expose(Card c)
{

}

void
simplePlayer::shuffle()
{

}

class countingPlayer : public Player {

 public:
	int bet(unsigned int bankroll, unsigned int minimum);
	bool draw(Card dealer, const Hand &player);
	void expose(Card c);
	void shuffle();
};

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
