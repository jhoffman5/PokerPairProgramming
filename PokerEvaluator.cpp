#include "PokerEvaluator.h"
#include <vector>
#include <iostream>

using namespace std;

PokerEvaluator::PokerEvaluator(vector<Card> cards)
{
	setHand(cards);
}
void PokerEvaluator::setHand(vector<Card> cards)
{
	for (int i = 0; i < cards.size(); i++)
		hand.push_back(cards[i]);
}