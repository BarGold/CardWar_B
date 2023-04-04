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
                        cout << cards.get_NumCard() << cards.get_shape() << endl;
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
                p1.add_to_stack(deck.at(i));
                i++;
                p2.add_to_stack(deck.at(i));
                i++;
        }
        this->_lastTurn = "";
        _allGame = "";
        cout << "hii bar" << endl;

        // now we redy to play
}
Game::~Game()
{
        // delete &p1;
        // delete &p2;
        // delete[] a;
        // delete[] a;
}

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
        // while (_p1.stacksize() != 0)
        // {
        //         playTurn();
        // }
        
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
}
void Game::printStats()
{
}
void Game::printLastTurn()
{
}
void Game::playTurn()
{
        cout << "My problem" << endl;
        int num_of_card = 0;
        int flag_draw = 0;
        _p2.set_win(-1);
        _p1.set_win(-1);
        // Returns a reference to the last card in the gamer stack
        Card p1_card = _p1.get_stack().back();
        Card p2_card = _p2.get_stack().back();
        card_turn.push_back(p1_card);
        card_turn.push_back(p2_card);
        _p2.get_stack().pop_back();
        _p1.get_stack().pop_back();

        num_of_card = 2;

        if (p1_card.get_NumCard() == p2_card.get_NumCard())
        {
                flag_draw = 1;
                _p2.set_win(2);
                _p1.set_win(2);
                while (flag_draw == 1)
                {
                        if (_p1.stacksize() == 0)
                        {
                                size_t i = 0;
                                while (i < num_of_card)
                                {
                                        _p1.add_to_cardesTaken(card_turn.at(i));
                                        i++;
                                        _p2.add_to_cardesTaken(card_turn.at(i));
                                        i++;
                                }
                                flag_draw = 0;
                        }
                        else if (_p1.stacksize() == 1)
                        {
                                num_of_card = num_of_card + 2;
                                size_t i = 0;
                                while (i < num_of_card)
                                {
                                        _p1.add_to_cardesTaken(card_turn.at(i));
                                        i++;
                                        _p2.add_to_cardesTaken(card_turn.at(i));
                                        i++;
                                }
                                flag_draw = 0;
                        }
                        else
                        {
                                //Place one card face down
                                num_of_card = num_of_card + 2;
                                p1_card = _p1.get_stack().back();
                                p2_card = _p2.get_stack().back();
                                card_turn.push_back(p1_card);
                                card_turn.push_back(p2_card);
                                _p2.get_stack().pop_back();
                                _p1.get_stack().pop_back();

                                // a new war
                                num_of_card = num_of_card + 2;
                                p1_card = _p1.get_stack().back();
                                p2_card = _p2.get_stack().back();
                                card_turn.push_back(p1_card);
                                card_turn.push_back(p2_card);
                                _p2.get_stack().pop_back();
                                _p1.get_stack().pop_back();

                                if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
                                {
                                        _p2.set_win(0);
                                        _p1.set_win(1);
                                        size_t i = 0;
                                        while (i < num_of_card)
                                        {
                                                _p1.add_to_cardesTaken(card_turn.at(i));
                                                i++;
                                        }
                                        flag_draw = 0;
                                }
                                else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
                                {
                                        _p2.set_win(1);
                                        _p1.set_win(0);
                                        size_t i = 0;
                                        while (i < num_of_card)
                                        {
                                                _p2.add_to_cardesTaken(card_turn.at(i));
                                                i++;
                                        }
                                        flag_draw = 0;
                                }
                        }
                }
        }
        else if (p1_card.get_NumCard() > p2_card.get_NumCard() || (p1_card.get_NumCard() == 2 && p2_card.get_NumCard() == 14))
        {
                _p2.set_win(0);
                _p1.set_win(1);
                size_t i = 0;
                while (i < num_of_card)
                {
                        _p1.add_to_cardesTaken(card_turn.at(i));
                        i++;
                }
        }
        else if (p1_card.get_NumCard() < p2_card.get_NumCard() || (p2_card.get_NumCard() == 2 && p1_card.get_NumCard() == 14))
        {
                _p2.set_win(1);
                _p1.set_win(0);
                size_t i = 0;
                while (i < num_of_card)
                {
                        _p2.add_to_cardesTaken(card_turn.at(i));
                        i++;
                }
        }
}
