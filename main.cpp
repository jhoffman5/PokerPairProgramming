#include <iostream>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Card.h"
#include "Deck.h"
#include "PokerEvaluator.h"

int main()
{
	cout << "Hello World!!!" << endl;

    Catch::Session().run();

	return 0;
}

TEST_CASE("Test Cards")
{
	SECTION("Test create bad cards")
	{
		Card c1(-10, "Hearts");
		Card c2(10, "Fish");
		Card c3(-10, "Fish");

		REQUIRE(c1.getNumericValue() == 2);
		REQUIRE(c1.getSuit() == "Hearts");
		REQUIRE(c2.getNumericValue() == 10);
		REQUIRE(c2.getSuit() == "Clubs");
		REQUIRE(c3.getNumericValue() == 2);
		REQUIRE(c3.getSuit() == "Clubs");
	}

	SECTION("Test create 52 cards")
	{
		string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
		for (int i = 0; i < 4; i++)			
		{
			for (int num = 2; num <= 14; num++)
			{
				Card c(num, suits[i]);
				REQUIRE(c.getNumericValue() == num);
				REQUIRE(c.getSuit() == suits[i]);
			}
		}		
	}  
     
	SECTION("Test toString()")
	{
		Card c1(3, "Diamonds");
		Card c2(10, "Hearts");
		Card c3(14, "Spades");

		REQUIRE(c1.toString() == "3 of Diamonds");
		REQUIRE(c2.toString() == "10 of Hearts");
		REQUIRE(c3.toString() == "Ace of Spades");
	}
}
TEST_CASE("Test Deck")
{
	SECTION("Test initializing deck")
	{
		Deck d1;

		REQUIRE(d1.getSize() == 52);
	}
	SECTION("Test Shuffle")
	{
		Deck d1;
		Deck d2 = d1;
		d2.shuffle();
		
		vector<Card> d1Deck = d1.getDeck();
		vector<Card> d2Deck = d2.getDeck();
		
		REQUIRE(d1Deck[0].toString() != d2Deck[0].toString());
	}
	SECTION("Test Deal")
	{
		Deck d;

		d.shuffle();

		REQUIRE(d.deal(5).size() == 5);

		REQUIRE(d.getSize() == 47);

		REQUIRE_THROWS(d.deal(60));
	}
}
TEST_CASE("Test Evaluator")
{
	SECTION("Test Royal Flush")
	{
		vector<Card> royalFlushHand;
		for(int i = 8; i < 15; i++)
		{
			Card c(i, "Hearts");
			royalFlushHand.push_back(c);
		}

		PokerEvaluator evaluateThis(royalFlushHand);
		//Should pass
		REQUIRE(evaluateThis.evaluate() == "Royal Flush");

		vector<Card> notARoyalFlush;
		for(int i = 2; i < 9; i++)
		{
			Card c(i, "Hearts");
			notARoyalFlush.push_back(c);
		}

		evaluateThis.setHand(notARoyalFlush);
		//evaluateThis doesn't have a royal flush now
		REQUIRE(evaluateThis.evaluate() != "Royal Flush");
	}
}