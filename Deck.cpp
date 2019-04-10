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
            string card = c.toString();
            deck.push_back(card);
        }
    }
}
int Deck::getSize()
{
    return deck.size();
}
void Deck::shuffle()
{
    vector<string> retDeck = deck;
    for (size_t i = 0; i < retDeck.size(); i++)
    {
        size_t pos = rand() % 52;
        string temp = retDeck[i];
        retDeck[i] = retDeck[pos];
        retDeck[pos] = temp;
    }
    
    deck = retDeck;
}
vector<string> Deck::getDeck()
{
    return deck;
}