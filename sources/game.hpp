#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>
#include "player.hpp"
using namespace std;


namespace ariel
{
};

class Game
{
private:
    Player &_p1;                        //player 1
    Player &_p2;                        //player 2

    string _lastTurn;                   //string of the last turn to turn
    string _allGame;                    //string of the prints all the turns played

    vector<Card> deck;                  //the deck of cards to play a game

    ////////////////////////// To Basic Statistics ////////////////////////////
    int _draw;                           // count how many draw had in the game;



    double draw_rate;
    int draw_amount; //  (draw within a draw counts as 2 draws. )


public:
    Game(Player& p1, Player& p2);
    // ~Game();

    // // the deck of cards to play a game
    // vector<Card> deck;
    // vector<Card> card_turn;

    // void add_to_cardesTurn(Card &card);
    // vector<Card> get_cardesTurn();


    int get_draw();

    /////// temp 

    // void set_maxTurns(int num);
    // int get_maxTurns();

    // void set_name_win();
    // string get_name_win();

    void playTurn();      // play turn
    void printLastTurn(); // print the last turn stats.

    void playAll();    // playes the game untill the end
    void printWiner(); // prints the name of the winning player
    void printLog();   // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won,
                       // <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
};

#endif