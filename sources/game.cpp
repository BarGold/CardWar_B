#include "game.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <stdio.h>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;
const int NUM_SHAPE = 4;
const int NUM_OF_NUMCARD = 13;

// to solv this pat i used https://www.geeksforgeeks.org/vector-in-cpp-stl/

namespace ariel
{
};
Game::Game(Player &p1, Player &p2) : _p1(p1), _p2(p2) , _lastTurn(""),_allGame(""),_draw(0),_turns(0)
{
        // we chack if player1 && player2 is a new player - becuse player can play just one game
        if(_p1.get_flag() == 1 || _p2.get_flag() == 1){
                throw("One of the players is already playing");
        }
        _p1.set_flag();
        _p2.set_flag();

        // first we need to creat the deck cards for the game
        int a[NUM_OF_NUMCARD] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // 14 - Ace card
        string b[NUM_SHAPE] = {"Spades", "Hearts", "Clubs", "Diamonds"};      // the shape of cards
        for (int i = 0; i < NUM_OF_NUMCARD; i++)
        {
                for (int j = 0; j < NUM_SHAPE; j++)
                {
                        Card cards(a[i], b[j]);
                        deck.push_back(cards);
                }
        }

        // now we need to shuffle the deck
        // to solv this pat i used https://stackoverflow.com/questions/26320612/c-random-shuffle-how-does-it-work
        // && https://en.cppreference.com/w/cpp/algorithm/random_shuffle
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g); //shuffle the cards in the deck

        // Each of the players receives 26 cards
        size_t i = 0;
        while (i < deck.size())
        {
                _p1.add_to_stack(deck.at(i));
                i++;
                _p2.add_to_stack(deck.at(i));
                i++;
        }

        // now we redy to play
}

void Game::playAll()
{
        while (_p1.stacksize() != 0 || _p2.stacksize() != 0)
        {
                playTurn();
        }
}

void Game::printWiner()
{
        if (_p1.cardesTaken() == _p2.cardesTaken())
        {
                cout << "The game ended in a draw" << endl;
        }
        else if (_p1.cardesTaken() > _p2.cardesTaken())
        {
                cout << "the Winner is: " << _p1.getName() << endl;
        }
        else if (_p1.cardesTaken() < _p2.cardesTaken())
        {
                cout << "the Winner is: " << _p2.getName() << endl;
        }
}

void Game::printLog()
{
        cout << _allGame << endl;
}

void Game::printStats()
{

        double temp = ((double)get_draw() / (double)_turns) * 100;

        cout << "------------------------------------- Basic Statistics:  -------------------------------------" << endl;
        cout << "This Game " << _p1.getName() << " VS " << _p2.getName() << endl;
        cout << "Amount Of Draws: " << get_draw() << endl;
        cout << "Draw Rate: " << temp << "%" << endl;
        cout << "Amount Of Turns: " << _turns << endl;

        temp = ((double)_p1.get_Wins() / (double)_turns) * 100;
        cout << "------------------ "
             << "Player One: " << _p1.getName() << " ------------------" << endl;
        cout << "Num of Wins: " << _p1.get_Wins() << endl;
        cout << "Num of Losses: " << _p1.get_Losses() << endl;
        cout << "Win Rate: " << temp << "%" << endl;
        cout << "Cards Won: " << _p1.get_cardsWon() << endl;

        temp = ((double)_p2.get_Wins() / (double)_turns) * 100;
        cout << "------------------ "
             << "Player Two: " << _p2.getName() << " ------------------" << endl;
        cout << "Num of Wins: " << _p2.get_Wins() << endl;
        cout << "Num of Losses: " << _p2.get_Losses() << endl;
        cout << "Win Rate: " << temp << "%" << endl;
        cout << "Cards Won: " << _p2.get_cardsWon() << endl;
}

int Game::get_draw()
{
        return this->_draw;
}

void Game::printLastTurn()
{
        cout << _lastTurn << endl;
}

string Card_Test(int num)
{
        if (num == 11)
        {
                return "Jack";
        }
        else if (num == 12)
        {
                return "Queen";
        }
        else if (num == 13)
        {
                return "King";
        }
        return "Ace";
}

void Game::playTurn()
{

        // test for "One player" - A player cannot play with himself :
        if (&_p1 == &_p2)
        {
                throw("A player cannot play with himself");
        }
        // the game is over
        if (_p1.stacksize() == 0 || _p2.stacksize() == 0)
        {
                throw("game over");
        }

        _lastTurn = "";
        int flag_draw = 0;
        int num_of_card = 0; // The number of cards on the board

        // Returns a reference to the last card in the gamer stack
        Card p1_card = _p1.get_stack().back();
        Card p2_card = _p2.get_stack().back();
        // removes the card from the stack
        _p2.removes_C_S();
        _p1.removes_C_S();

        num_of_card = 2;
        _turns = _turns + 1;

        // to the print turn 11 = "Jack" | 12="Queen" | 13 = "King" | 14 = "Ace"
        string p1_card_Test = "";
        string p2_card_Test = "";
        if (p1_card.get_NumCard() > 10)
        {
                p1_card_Test = Card_Test(p1_card.get_NumCard());
        }
        else
        {
                p1_card_Test = to_string(p1_card.get_NumCard());
        }
        if (p2_card.get_NumCard() > 10)
        {
                p2_card_Test = Card_Test(p2_card.get_NumCard());
        }
        else
        {
                p2_card_Test = to_string(p2_card.get_NumCard());
        }

        // if we have a draw :
        if (p1_card.get_NumCard() == p2_card.get_NumCard())
        {
                flag_draw = 1;

                while (flag_draw == 1)
                {
                        _draw = _draw + 1;
                        _lastTurn = _lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". Draw. ";
                        if (_p1.stacksize() == 0)
                        {
                                num_of_card = num_of_card / 2; // Divide the cards on the board into 2
                                _p1.set_cardesTaken(num_of_card);
                                _p2.set_cardesTaken(num_of_card);
                                flag_draw = 0; // the draw over - No more cards to play
                        }
                        else if (_p1.stacksize() == 1)
                        {
                                num_of_card = num_of_card + 2;
                                num_of_card = num_of_card / 2; // Divide the cards on the board into 2
                                _p2.removes_C_S();
                                _p1.removes_C_S();
                                _p1.set_cardesTaken(num_of_card);
                                _p2.set_cardesTaken(num_of_card);
                                flag_draw = 0; // the draw over - No more cards to play
                        }
                        else
                        {
                                //Place one card face down
                                num_of_card = num_of_card + 2;
                                p1_card = _p1.get_stack().back();
                                p2_card = _p2.get_stack().back();

                                _p2.removes_C_S();
                                _p1.removes_C_S();

                                // a new war
                                num_of_card = num_of_card + 2;
                                p1_card = _p1.get_stack().back();
                                p2_card = _p2.get_stack().back();

                                _p2.removes_C_S();
                                _p1.removes_C_S();

                                // to the print turn 11 = "Jack" | 12="Queen" | 13 = "King" | 14 = "Ace"
                                if (p1_card.get_NumCard() > 10)
                                {
                                        p1_card_Test = Card_Test(p1_card.get_NumCard());
                                }
                                else
                                {
                                        p1_card_Test = to_string(p1_card.get_NumCard());
                                }
                                if (p2_card.get_NumCard() > 10)
                                {
                                        p2_card_Test = Card_Test(p2_card.get_NumCard());
                                }
                                else
                                {
                                        p2_card_Test = to_string(p2_card.get_NumCard());
                                }

                                // if p1 win the draw

                                if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
                                {
                                        _p1.set_Wins(1);
                                        _p2.set_Losses(1);
                                        _lastTurn = _lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p1.getName() + " wins.";
                                        _p1.set_cardsWon(p1_card_Test + " of " + p1_card.get_shape());
                                        _p1.set_cardesTaken(num_of_card);
                                        flag_draw = 0;
                                }

                                // if p2 win the draw
                                else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
                                {
                                        _p2.set_Wins(1);
                                        _p1.set_Losses(1);
                                        _lastTurn = _lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p2.getName() + " wins.";
                                        _p2.set_cardsWon(p2_card_Test + " of " + p2_card.get_shape());
                                        _p2.set_cardesTaken(num_of_card);
                                        flag_draw = 0;
                                }
                        }
                }
        }
        // if p1 win
        else if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
        {
                _p1.set_Wins(1);
                _p2.set_Losses(1);
                _lastTurn = _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                            _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p1.getName() + " wins.";
                _p1.set_cardsWon(p1_card_Test + " of " + p1_card.get_shape());
                _p1.set_cardesTaken(num_of_card);
        }
        // if p2 win
        else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
        {
                _p2.set_Wins(1);
                _p1.set_Losses(1);
                _lastTurn = _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                            _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p2.getName() + " wins.";

                _p2.set_cardsWon(p2_card_Test + " of " + p2_card.get_shape());
                _p2.set_cardesTaken(num_of_card);
        }
        if (_p1.stacksize() == 0 || _p2.stacksize() == 0)
        {
                _allGame = _allGame + _lastTurn;
        }
        else
        {
                _allGame = _allGame + _lastTurn + "\n";
        }
}
