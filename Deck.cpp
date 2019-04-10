#include "Deck.h"
#include <vector>
#include <iostream>

using namespace std;

Deck::Deck()
{
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(int suit = 0; suit < 4; suit++){
        for(int num = 2; num < 15; num++){
            Card c(num, suits[suit]);
            deck.push_back(c);
        }
    }
}
int Deck::getSize()
{
    return deck.size();
}
void Deck::shuffle()
{
    vector<Card> retDeck = deck;
    for (size_t i = 0; i < retDeck.size(); i++)
    {
        size_t pos = rand() % 52;
        Card temp = retDeck[i];
        retDeck[i] = retDeck[pos];
        retDeck[pos] = temp;
    }

    deck = retDeck;
}
vector<Card> Deck::getDeck()
{
    return deck;
}
vector<Card> Deck::deal(int num)
{
    vector<Card> hand;
    if(num > deck.size())
    {
        throw "Not enough cards to deal";
    }
    else
    {
        for(int i = 0; i < num; i++)
        {
            hand.push_back(deck[deck.size() - 1]);
            deck.pop_back();
        }
    }
    return hand;
}