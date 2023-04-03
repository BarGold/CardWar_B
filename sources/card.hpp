#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

namespace ariel
{
};

class Card
{
private:
    int _num;
    string _shape; // Spades , Hearts , Clubs , Diamonds
public:
    Card(int num , string shape);
};

#endif