#include "card.hpp"

namespace ariel
{};
    // constructor
    Card::Card(int num, string shape)
    {
        this->_num = num;
        this->_shape = shape;
    }
    // // destructor
    // Card::~Card()
    // {
    // }
    // get the number of Cards
    int Card::get_NumCard()
    {
        return this->_num;
    }
    // get the shape of Cards
    string Card::get_shape()
    {
        return this->_shape;
    }

