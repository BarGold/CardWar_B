#include "card.hpp"

namespace ariel
{
};
// constructor
Card::Card(int num, string shape):_num(num),_shape(shape)
{
}

// get the number of Cards
int Card::get_NumCard()
{
    return _num;
}

// get the shape of Cards
string Card::get_shape()
{
    return _shape;
}
