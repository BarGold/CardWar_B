#include "player.hpp"

namespace ariel
{
    Player::Player(){}
    
    Player::Player(string name)
    {
        this->_name = name;
    }

    string Player::getName()
    {
        return _name;
    }

    //get the stack size 
    int Player::stacksize()
    {
        return _stackSize;
    }

    void Player::set_stacksize()
    {

    }

    //get the cards this player has won
    int Player::cardesTaken()
    {
        return _cardesTaken;
    }
    
    void Player::set_cardesTaken()
    {
    }

    void Player::set_win_rate()
    {
    }
    double Player::get_win_rate()
    {
        return 0;
    }

    void Player::set_win()
    {
    }
    int Player::get_win()
    {
        return _win;
    }

}