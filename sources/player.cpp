#include "player.hpp"
#include "card.hpp"
#include <vector>

namespace ariel
{};
    
    Player::Player(string name)
    {
        this->_name = name;
        this->_cardesTakenSize = 0;
        this->_stackSize = 0;
        this->_win = -1;
    }
    Player::~Player()
    {
        _stack.clear();
        _cardesTaken.clear();
    }

    void Player::add_to_stack(Card& card){
        _stack.push_back(card);
    }

    vector<Card> Player::get_stack(){
        return this->_stack;
    }

    void Player::add_to_cardesTaken(Card& card){
        _cardesTaken.push_back(card);
    }

    vector<Card> Player::get_cardesTaken(){
        return this->_cardesTaken;
    }

    string Player::getName()
    {
        return _name;
    }

    //get the stack size 
    int Player::stacksize()
    {
        return _stack.size();
    }


    //get the cards this player has won
    int Player::cardesTaken()
    {
        return _cardesTaken.size();
    }
    

    void Player::set_win_rate()
    {
    }
    double Player::get_win_rate()
    {
        return 0;
    }

    void Player::set_win(int n)
    {
        _win = n;
    }
    int Player::get_win()
    {
        return _win;
    }
