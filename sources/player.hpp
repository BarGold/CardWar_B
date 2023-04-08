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
    string _name;            // name of player
    vector<Card> _stack;    // cards in the player stack
    int _cardesTaken;       // num of cards that the player has won

    ////////////////////////// To Basic Statistics ////////////////////////////
    int _Wins;               //num of wins to player
    int _Losses;             //num of losses to player
    string _cardsWon;        //to print the cards that the player has won


    // vector<Card> _cardesTaken;  // cards that the player has won
    // int _win;               // if he win 1 , loss 0 , Draw 2 , new player/new turn -1

    // int _stackSize;   // amount of cards left
    // double win_rate;
    // Card card_Play; // player card for turn

public:
    Player(string name);
    string getName();

    void add_to_stack(Card &card);          // add card to stack player 
    vector<Card> get_stack();               // get the stack of player
    void removes_C_S();                     // removes card from stack player 
    int stacksize();                        // get the stack size

    void set_cardesTaken(int num);         // add num of cards that the player has won
    int cardesTaken();                     // num of cards that the player has won

    ////////////////////////// To Basic Statistics ////////////////////////////

    // get & set of wins to player
    void set_Wins(int num);
    int get_Wins();

    // get & set of losses to player
    void set_Losses(int num);
    int get_Losses();

    // get & set of the cards that the player has won
    void set_cardsWon(string s);
    string get_cardsWon();

    // void set_win_rate();
    // double get_win_rate();

    // void set_win(int n);
    // int get_win();
};

#endif