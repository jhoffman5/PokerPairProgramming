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