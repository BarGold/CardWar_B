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
    string _name;               // name of player
    vector<Card> _stack;         // cards in the player stack
    int _cardesTaken;
    // vector<Card> _cardesTaken;  // cards that the player has won
    int _win;               // if he win 1 , loss 0 , Draw 2 , new player/new turn -1


    // int _stackSize;   // amount of cards left
    // double win_rate;
    // Card card_Play; // player card for turn

public:
    Player(string name);
    // ~Player();
    string getName();

    void add_to_stack(Card& card);
    vector<Card> get_stack();
    void removes_C_S();
    int stacksize();

    // void add_to_cardesTaken(Card& card);
    // vector<Card> get_cardesTaken();
    void set_cardesTaken(int num);
    int cardesTaken();


    //////////////////////////

    void set_win_rate();
    double get_win_rate();

    void set_win(int n);
    int get_win();
};

#endif