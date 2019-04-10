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

    bool tenInHand = false;
    for(int i = 0; i < hand.size(); i++)
    {
		if ((hand[i].getNumericValue() == 10) && (hand[i].getSuit() == flushSuit)) {
			tenInHand = true;
			break;
		}
    }

    if(!tenInHand)
        return false;
    
    bool jackInHand = false;
    for(int i = 0; i < hand.size(); i++)
    {
		if (hand[i].getNumericValue() == 11 && hand[i].getSuit() == flushSuit) {
			jackInHand = true;
			break;
		}
    }

    if(!jackInHand)
        return false;

    bool queenInHand = false;
    for(int i = 0; i < hand.size(); i++)
    {
		if (hand[i].getNumericValue() == 12 && hand[i].getSuit() == flushSuit) {
			queenInHand = true;
			break;
		}
    }

    if(!queenInHand)
        return false;

    bool kingInHand = false;
    for(int i = 0; i < hand.size(); i++)
    {
		if (hand[i].getNumericValue() == 13 && hand[i].getSuit() == flushSuit) {
			kingInHand = true;
			break;
		}
	
    }

    if(!kingInHand)
        return false;

    bool aceInHand = false;
    for(int i = 0; i < hand.size(); i++)
    {
		if (hand[i].getNumericValue() == 14 && hand[i].getSuit() == flushSuit) {
			aceInHand = true;
			break;
		}
    }

    if(!aceInHand)
        return false;
	
	return true;
}