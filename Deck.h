#pragma once
#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
public:
    Deck();
    
private:
    vector<Card> deck;
};