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
    vector<Card> _stack;


    // int _stackSize;   // amount of cards left


    // double win_rate;

    int _win;        // if he win 1 , loss 0 , Draw 2 , new player -1
                    // if have draw or tico 
    // Card card_Play; // player card for turn

public:
    Player(string name);
    void add_to_stack(Card& card);
    vector<Card> get_stack();
    

    string getName();

    int stacksize();
    void set_stacksize();

    int cardesTaken();
    void set_cardesTaken(int num_of_card);

    void set_win_rate();
    double get_win_rate();

    void set_win(int n);
    int get_win();
};

#endif