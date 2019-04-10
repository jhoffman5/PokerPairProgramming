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
    vector<string> getDeck();

    void shuffle();

private:
    vector<string> deck;
};