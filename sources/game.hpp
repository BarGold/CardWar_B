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
    Player &_p1; //player 1
    Player &_p2; //player 2

    string _lastTurn; //string of the last turn to turn
    string _allGame;  //string of the prints all the turns played

    vector<Card> deck; //the deck of cards to play a game

    ////////////////////////// To Basic Statistics ////////////////////////////
    int _draw;  // count how many draw had in the game;
    int _turns; // num of turns in the game;

public:
    Game(Player &p1, Player &p2);

    int get_draw();

    void playTurn();      // play turn
    void printLastTurn(); // print the last turn stats.

    void playAll();    // playes the game untill the end
    void printWiner(); // prints the name of the winning player
    void printLog();   // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won,
                       // <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
};

#endif