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

}

extern Player *get_Counting()
{

}
