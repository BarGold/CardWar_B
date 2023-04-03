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
    int _cardesTakenSize; // amount of cards this player has won.
    int _stackSize;
    vector<Card> _stack;
    vector<Card> _cardesTaken;


    // int _stackSize;   // amount of cards left


    // double win_rate;

    int _win;        // if he win 1 , loss 0 , Draw 2 , new player/new turn -1
    // Card card_Play; // player card for turn

public:
    Player(string name);
    ~Player();
    void add_to_stack(Card &card);
    vector<Card> get_stack();

    void add_to_cardesTaken(Card &card);
    vector<Card> get_cardesTaken();

    string getName();

    int stacksize();
    void set_stacksize(int num);

    int cardesTaken();
    void set_cardesTaken(int num_of_card);

    void set_win_rate();
    double get_win_rate();

    void set_win(int n);
    int get_win();
};

#endif