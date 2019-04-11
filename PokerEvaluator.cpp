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
    hand.clear();
	for (int i = 0; i < cards.size(); i++)
		hand.push_back(cards[i]);
}
string PokerEvaluator::evaluate()
{
    if(isRoyalFlush())
    {
        return "Royal Flush";
    }
	else
	{
		return "High Card Wins";
	}
}
bool PokerEvaluator::isRoyalFlush()
{ 
    int hearts = 0;
    int diamonds = 0;
    int spades = 0;
    int clubs = 0;
    for(int i = 0; i < hand.size(); i++)
    {
        if(hand[i].getSuit() == "Hearts")
        {
            hearts++;
        }
        else if(hand[i].getSuit() == "Diamonds")
        {
            diamonds++;
        }
        else if(hand[i].getSuit() == "Clubs")
        {
            clubs++;
        }
        else
        {
            spades++;
        }
    }

	if(!((hearts>4)||(diamonds>4)||(clubs>4)||(spades>4)))
    {
        return false;
    }

    string flushSuit;
    if(hearts>4)
        flushSuit = "Hearts";
    else if(diamonds>4)
        flushSuit = "Diamonds";
    else if(clubs>4)
        flushSuit = "Clubs";
    else
        flushSuit = "Spades";

    int flushCards = 0;
    for(size_t i = 0; i < hand.size(); i++)
    {
        if(hand[i].getNumericValue()>9 && hand[i].getSuit() == flushSuit)
        {
            flushCards++;
        }
    }

    if(flushCards==5)
    {
        return true;
    }
    else
    {
        return false;
    }
}