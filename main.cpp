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

		REQUIRE_THROWS(d.deal(101));
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
	SECTION("Test Straight Flush")
	{
		vector<Card> straightFlush;
		for(int i = 2; i < 9; i++)
		{
			Card c(i, "Hearts");
			straightFlush.push_back(c);
		}
		PokerEvaluator evaluateThis(straightFlush);

		REQUIRE(evaluateThis.evaluate() == "Straight Flush");

		vector<Card> notStraightFlush;
		for(int i = 2; i < 5; i++)
		{
			Card c(i, "Hearts");
			notStraightFlush.push_back(c);
		}
		for(int i = 5; i < 9; i++)
		{
			Card c(i, "Clubs");
			notStraightFlush.push_back(c);
		}

		evaluateThis.setHand(notStraightFlush);
		REQUIRE(evaluateThis.evaluate() != "Straight Flush");	
	}
	SECTION("Test Flush")
	{
		vector<Card> flush;
		for (int i = 2; i < 5; i++)
		{
			Card c(i, "Hearts");
			flush.push_back(c);
		}
		for (int i = 7; i < 11; i++)
		{
			Card c(i, "Hearts");
			flush.push_back(c);
		}
		PokerEvaluator evaluateThis(flush);

		REQUIRE(evaluateThis.evaluate() == "Flush");
	}
	SECTION("Test Four of a Kind")
	{
		Card a(2, "Spades");
		Card b(2, "Diamonds");
		Card c(2,"Clubs");
		Card d(2, "Hearts");
		Card e(4,"Diamonds");
		Card f(3,"Clubs");
		Card g(9,"Hearts");

		vector<Card> fourOfAKind = {a,b,c,d,e,f,g};
		PokerEvaluator evaluateThis(fourOfAKind);

		REQUIRE(evaluateThis.evaluate() == "Four Of A Kind");

		b.setNumericValue(3);
		
		vector<Card> notFourOfAKind = { a,b,c,d,e,f,g };
		evaluateThis.setHand(notFourOfAKind);
		
		REQUIRE(evaluateThis.evaluate() != "Four Of A Kind");
	}
	SECTION("Test Full House")
	{
		Card a(2, "Spades");
		Card b(2, "Diamonds");
		Card c(2,"Clubs");
		Card d(3, "Hearts");
		Card e(3,"Diamonds");
		Card f(7,"Clubs");
		Card g(9,"Hearts");

		vector<Card> fullHouse = {a,b,c,d,e,f,g};
		PokerEvaluator evaluateThis(fullHouse);

		REQUIRE(evaluateThis.evaluate() == "Full House");	

		b.setNumericValue(9);

		vector<Card> notFull = { a,b,c,d,e,f,g };
		evaluateThis.setHand(notFull);

		REQUIRE(evaluateThis.evaluate() != "Full House");
	}
	SECTION("Test Straight")
	{
		Card a(2, "Spades");
		Card b(3, "Diamonds");
		Card c(4, "Clubs");
		Card d(5, "Hearts");
		Card e(6, "Diamonds");
		Card f(10, "Clubs");
		Card g(9, "Hearts");

		vector<Card> straight = { a,b,c,d,e,f,g };
		PokerEvaluator evaluateThis(straight);

		REQUIRE(evaluateThis.evaluate() == "Straight");
	}
}