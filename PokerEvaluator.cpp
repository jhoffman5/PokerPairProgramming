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
void PokerEvaluator::sortByNumeric()
{
    for(int i = 0; i < hand.size(); i++)
    {
        for(int j = i+1; j < hand.size(); j++)
        {
            if(hand[i].getNumericValue() > hand[j].getNumericValue())
            {
                swap(hand[i], hand[j]);
            }
        }
    }
}
string PokerEvaluator::evaluate()
{
    if(isRoyalFlush())
    {
        return "Royal Flush";
    }
    else if(isStraightFlush())
    {
        return "Straight Flush";
    }
    else if(isFourOfAKind())
    {
        return "Four Of A Kind";
    }
    else if(isFullHouse())
    {
        return "Full House";
    }
	else if (isFlush())
	{
		return "Flush";
	}
	else if (isStraight())
	{
		return "Straight";
	}
    else if(isThreeOfAKind())
    {
        return "Three Of A Kind";
    }
    else if(isTwoPair())
    {
        return "Two Pair";
    }
    else if(isPair())
    {
        return "Pair";
    }
	else
	{
		return "High Card";
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
bool PokerEvaluator::isStraightFlush()
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
    
    vector<Card> flushHand;
    vector<Card> saveHand = hand;

    for(int i = 0; i < hand.size(); i++)
    {
        if(hand[i].getSuit() == flushSuit)
        {
            flushHand.push_back(hand[i]);
        }
    }

    hand = flushHand;
    
    (*this).sortByNumeric();

    int counter = 0;

    for(int i = 0; i < hand.size() - 1; i++)
    {
        if(hand[i].getNumericValue() != hand[i+1].getNumericValue() - 1)
        {
            counter = 0;
        }
		else
		{
			counter++;
		}

        if(counter==4)
        {
            return true;
        }
    }

    return false;

    //restore the hand
    hand = saveHand;
}
bool PokerEvaluator::isFourOfAKind()
{
    int cardVals[15] = {0};

    for(int i = 0; i < hand.size(); i++)
    {
        cardVals[hand[i].getNumericValue()]++;
    }

    for(int i = 2; i < 15; i++)
    {
        if(cardVals[i] > 3)
        {
            return true;
        }
    }

    return false;
}
bool::PokerEvaluator::isFullHouse()
{
	int cardVals[15] = { 0 };

	for (int i = 0; i < hand.size(); i++)
	{
		cardVals[hand[i].getNumericValue()]++;
	}

	bool hasThree = false;
	bool hasTwo = false;
	for (int i = 2; i < 15; i++)
	{
		if (cardVals[i] == 3)
		{
			 hasThree = true;
		}
		if (cardVals[i] == 2)
		{
			hasTwo = true;
		}
	}

	if (hasThree && hasTwo)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool PokerEvaluator::isFlush()
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
    else
    {
        return true;
    }
}
bool PokerEvaluator::isStraight()
{
	vector<Card> originalHand = hand;

	for (int i = 0; i < hand.size() - 1; i++)
	{
		if (hand[i].getNumericValue() == hand[i + 1].getNumericValue())
		{
			hand.erase(hand.begin() + i);
		}
	}

	(*this).sortByNumeric();

	int counter = 0;

	for (int i = 0; i < hand.size() - 1; i++)
	{
		if (hand[i].getNumericValue() != hand[i + 1].getNumericValue() - 1)
		{
			counter = 0;
		}
		else
		{
			counter++;
		}

		if (counter == 4)
		{
			hand = originalHand;
			return true;
		}
	}

	hand = originalHand;
	return false;
}
bool PokerEvaluator::isThreeOfAKind()
{
    int cardVals[15] = { 0 };

	for (int i = 0; i < hand.size(); i++)
	{
		cardVals[hand[i].getNumericValue()]++;
	}

	for (int i = 2; i < 15; i++)
	{
		if (cardVals[i] == 3)
		{
			 return true;
		}
	}

	return false;
}
bool PokerEvaluator::isTwoPair()
{
    int cardVals[15] = { 0 };

	for (int i = 0; i < hand.size(); i++)
	{
		cardVals[hand[i].getNumericValue()]++;
	}

	int hasPairs = 0;
	for (int i = 2; i < 15; i++)
	{
		if (cardVals[i] == 2)
		{
			hasPairs++;
		}
	}

	if (hasPairs == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool PokerEvaluator::isPair()
{
        int cardVals[15] = { 0 };

	for (int i = 0; i < hand.size(); i++)
	{
		cardVals[hand[i].getNumericValue()]++;
	}

	for (int i = 2; i < 15; i++)
	{
		if (cardVals[i] == 2)
		{
			return true;
		}
    }

    return false;
}