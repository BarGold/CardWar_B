#include "player.hpp"
#include "card.hpp"
#include <vector>

namespace ariel
{
};

// constructor
Player::Player(string name):_name(name) , _cardesTaken(0),_flag(0),_Wins(0),_Losses(0) , _cardsWon("")
{
}

// get the name of player
string Player::getName()
{
    return _name;
}

// add card to stack player
void Player::add_to_stack(Card &card)
{
    _stack.push_back(card);
}

// get the stack of player
vector<Card> Player::get_stack()
{
    return _stack;
}

// removes card from stack player
void Player::removes_C_S()
{
    _stack.pop_back();
}

//get the stack size
int Player::stacksize()
{
    return _stack.size();
}

//get the num of cards that the player has won
int Player::cardesTaken()
{
    return _cardesTaken;
}

// add num of cards that the player has won
void Player::set_cardesTaken(int num)
{
    _cardesTaken = _cardesTaken + num;
}

// get & set of wins to player
void Player::set_Wins(int num)
{
    _Wins = _Wins + num;
}
int Player::get_Wins()
{
    return _Wins;
}

// get & set of losses to player
void Player::set_Losses(int num)
{
    _Losses = _Losses + num;
}
int Player::get_Losses()
{
    return _Losses;
}

// get & set of the cards that the player has won
void Player::set_cardsWon(const string &s)
{
    _cardsWon = s + " , " + _cardsWon;
}
string Player::get_cardsWon()
{
    return _cardsWon;
}

void Player::set_flag()
{
    _flag = 1;
}
int Player::get_flag()
{
    return _flag;
}
