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
    string _name;        // name of player
    vector<Card> _stack; // cards in the player stack
    int _cardesTaken;    // num of cards that the player has won

    int _flag; // this flag we use to chack if the player play one game
               // 0 - new gmae , 1- in a game

    ////////////////////////// To Basic Statistics ////////////////////////////
    int _Wins;        //num of wins to player
    int _Losses;      //num of losses to player
    string _cardsWon; //to print the cards that the player has won

public:
    Player(string name);
    string getName();

    void add_to_stack(Card &card); // add card to stack player
    vector<Card> get_stack();      // get the stack of player
    void removes_C_S();            // removes card from stack player
    int stacksize();               // get the stack size

    void set_cardesTaken(int num); // add num of cards that the player has won
    int cardesTaken();             // num of cards that the player has won

    // this flag we use to chack if the player play one game
    // 0 - new gmae , 1- in a game
    void set_flag();
    int get_flag();

    ////////////////////////// To Basic Statistics ////////////////////////////

    // get & set of wins to player
    void set_Wins(int num);
    int get_Wins();

    // get & set of losses to player
    void set_Losses(int num);
    int get_Losses();

    // get & set of the cards that the player has won
    void set_cardsWon(const string &s);
    string get_cardsWon();
};

#endif