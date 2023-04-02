#include "player.hpp"

namespace ariel
{
    Player::Player()
    {
    }
    Player::Player(string name)
    {
        this->_name = name;
    }

    string Player::getName()
    {
        return "";
    }

    int Player::stacksize()
    {
        return 0;
    }
    void Player::set_stacksize()
    {
    }

    int Player::cardesTaken()
    {
        return 0;
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
        return 1;
    }

}