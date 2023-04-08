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
    Card(int num, string shape);
    // ~Card();
    int get_NumCard();  // get the number of Cards
    string get_shape(); // get the shape of Cards
};

#endif