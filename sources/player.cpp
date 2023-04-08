#include "player.hpp"
#include "card.hpp"
#include <vector>

namespace ariel
{
};

// constructor
Player::Player(string name)
{
    this->_name = name;
    this->_cardesTaken = 0;
    this->_Losses = 0;
    this->_Wins = 0;
    this->_cardsWon = "";
}

// get the name of player
string Player::getName()
{
    return this->_name;
}

// add card to stack player 
void Player::add_to_stack(Card &card)
{
    this->_stack.push_back(card);
}

// get the stack of player 
vector<Card> Player::get_stack()
{
    return this->_stack;
}

// removes card from stack player 
void Player::removes_C_S()
{
    this->_stack.pop_back();
}

//get the stack size
int Player::stacksize()
{
    return _stack.size();
}

//get the num of cards that the player has won
int Player::cardesTaken()
{
    return this->_cardesTaken;
}

// add num of cards that the player has won
void Player::set_cardesTaken(int num)
{
    this->_cardesTaken = this->_cardesTaken + num;
}

// get & set of wins to player
void Player::set_Wins(int num)
{
    this->_Wins = this->_Wins + num;
}
int Player::get_Wins()
{
    return this->_Wins;
}

// get & set of losses to player
void Player::set_Losses(int num)
{
    this->_Losses = this->_Losses + num;
}
int Player::get_Losses()
{
    return this->_Losses;
}

// get & set of the cards that the player has won
void Player::set_cardsWon(string s){
    this->_cardsWon = s + " , "+this->_cardsWon;
}
string Player::get_cardsWon(){
    return this->_cardsWon;
}



// void Player::set_win_rate()
// {
// }
// double Player::get_win_rate()
// {
//     return 0;
// }

// void Player::set_win(int n)
// {
//     _win = n;
// }
// int Player::get_win()
// {
//     return _win;
// }
