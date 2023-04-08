#include "game.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <stdio.h>
#include <random>
#include <iostream>
using namespace std;
const int NUM_SHAPE = 4;
const int NUM_OF_NUMCARD = 13;

// to solv this pat i used https://www.geeksforgeeks.org/vector-in-cpp-stl/

namespace ariel
{
};
Game::Game(Player &p1, Player &p2) : _p1(p1), _p2(p2)
{
        // !!!!!!!
        // first we need to creat the deck cards for the game
        // we creat 52 cards
        // vector<Card> deck;
        int a[NUM_OF_NUMCARD] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // 14 - Ace card
        string b[NUM_SHAPE] = {"Spades", "Hearts", "Clubs", "Diamonds"};
        for (int i = 0; i < NUM_OF_NUMCARD; i++)
        {
                for (int j = 0; j < NUM_SHAPE; j++)
                {
                        Card cards(a[i], b[j]);
                        deck.push_back(cards);
                }
        }
        //!!!!!!!
        // now we need to shuffle the deck
        // to get random numbers each run
        random_device rd;
        mt19937 g(rd());
        // Use std::shuffle to randomly shuffle the cards in the deck
        shuffle(deck.begin(), deck.end(), g);

        // ***
        // Each of the players receives 26 cards
        size_t i = 0;
        while (i < deck.size())
        {
                _p1.add_to_stack(deck.at(i));
                i++;
                _p2.add_to_stack(deck.at(i));
                i++;
        }
        _lastTurn = "";
        _allGame = "";

        // now we redy to play
}

// Game::~Game()
// {
//         // delete &p1;
//         // delete &p2;
//         // delete[] a;
//         // delete[] a;
// }

void Game::set_war()
{
}
int Game::get_war()
{
        return 0;
}

void Game::set_name_win()
{
}
string Game::get_name_win()
{
        return "";
}

void Game::playAll()
{
        while (_p1.stacksize() != 0)
        {
                playTurn();
        }
}

void Game::printWiner()
{
        if (_p1.cardesTaken() == _p2.cardesTaken())
        {
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
}

void Game::printLastTurn()
{
        cout << _lastTurn << endl;
}

string Card_Test(int num){
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
        if(&_p1 == &_p2){
                throw ("A player cannot play with himself");
        }
        if(_p1.stacksize() == 0 || _p2.stacksize() == 0){
                throw ("game over");
        }
        
        _lastTurn = "";

        int flag_draw = 0;
        _p2.set_win(-1);
        _p1.set_win(-1);

        int num_of_card = 0;
        // Returns a reference to the last card in the gamer stack
        Card p1_card = _p1.get_stack().back();
        Card p2_card = _p2.get_stack().back();       
        _p2.removes_C_S();
        _p1.removes_C_S();

        num_of_card = 2;

        string p1_card_Test = "";
        string p2_card_Test = "";
        if (p1_card.get_NumCard() > 10)
        {
                p1_card_Test = Card_Test(p1_card.get_NumCard());
        }
        else{
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

        if (p1_card.get_NumCard() == p2_card.get_NumCard())
        {
                flag_draw = 1;
                _p2.set_win(2);
                _p1.set_win(2);
                
                while (flag_draw == 1)
                {
                        _lastTurn = _lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() +
                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". Draw. ";
                        if (_p1.stacksize() == 0)
                        {
                                num_of_card = num_of_card / 2;
                                _p1.set_cardesTaken(num_of_card);
                                _p2.set_cardesTaken(num_of_card);
                                flag_draw = 0;
                        }
                        else if (_p1.stacksize() == 1)
                        {
                                num_of_card = num_of_card + 2;
                                num_of_card = num_of_card / 2;
                                _p1.set_cardesTaken(num_of_card);
                                _p2.set_cardesTaken(num_of_card);
                                flag_draw = 0;
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

                                if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
                                {
                                        _p2.set_win(0);
                                        _p1.set_win(1);
                                        _lastTurn =_lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p1.getName() + " wins.";
                                        _p1.set_cardesTaken(num_of_card);
                                        flag_draw = 0;
                                }
                                else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
                                {
                                        _p2.set_win(1);
                                        _p1.set_win(0);
                                        _lastTurn = _lastTurn + _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape() + " " +
                                                    _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p2.getName() + " wins.";
                                        _p2.set_cardesTaken(num_of_card);
                                        flag_draw = 0;
                                }
                        }
                }
        }
        else if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
        {
                _p2.set_win(0);
                _p1.set_win(1);
                _lastTurn = _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape()+ " " +
                _p2.getName() + " played " + p2_card_Test + " of " + p2_card.get_shape() + ". " + _p1.getName() + " wins." ;
                _p1.set_cardesTaken(num_of_card);
        }
        else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
        {
                _p2.set_win(1);
                _p1.set_win(0);
                _lastTurn = _p1.getName() + " played " + p1_card_Test + " of " + p1_card.get_shape()+ " " +
                _p2.getName() + " played " + p2_card_Test+ " of " + p2_card.get_shape() + ". " + _p2.getName() + " wins." ;
                _p2.set_cardesTaken(num_of_card);
        }
        _allGame = _lastTurn + "\n" + _allGame ; 
}
