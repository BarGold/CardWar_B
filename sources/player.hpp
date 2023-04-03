#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel
{
};

class Player
{

private:
    string _name;     // name of player
    int _cardesTaken; // amount of cards this player has won.


    // int _stackSize;   // amount of cards left


    // double win_rate;

    // int _win;        // if he win 1 , loss 0 , Draw 2
    // Card card_Play; // player card for turn

public:
    Player(string name);
    vector<Card> _stack();

    string getName();

    int stacksize();
    void set_stacksize();

    int cardesTaken();
    void set_cardesTaken();

    void set_win_rate();
    double get_win_rate();

    void set_win();
    int get_win();
};

#endif