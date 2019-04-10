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
    vector<string> deal(int num);

private:
    vector<string> deck;
};