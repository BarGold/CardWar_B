#include "card.hpp"

namespace ariel
{ };
Card::Card(int num, string shape)
{
    this->_num = num;
    this->_shape = shape;
}

int Card::get_NumCard()
{
    return this->_num;
}

Card::~Card() {
}
    