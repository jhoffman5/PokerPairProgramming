#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

class PokerEvaluator
{
    public:
		PokerEvaluator(vector<Card> cards);

		void setHand(vector<Card> cards);

    private:
		vector<Card> hand;
};