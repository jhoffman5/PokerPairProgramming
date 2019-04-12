#pragma once
#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
public:
    Deck();
    
    int getSize();
    vector<Card> getDeck();

    void shuffle();
    vector<Card> deal(int num);

private:
    vector<Card> deck;
};