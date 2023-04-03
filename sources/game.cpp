#include "game.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
const int NUM_SHAPE = 4;
const int NUM_OF_NUMCARD = 13; 

// to solv this pat i used https://www.geeksforgeeks.org/vector-in-cpp-stl/

namespace ariel
{
        Game::Game(Player &p1, Player &p2) : _p1(p1), _p2(p2)
        {
                // !!!!!!!
                // first we need to creat the deck cards for the game
                // we creat 52 cards
                vector<Card> deck(52);
                int a[NUM_OF_NUMCARD] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
                string b[NUM_SHAPE] = {"Spades", "Hearts", "Clubs", " Diamonds"};
                for (int i = 0; i < NUM_OF_NUMCARD; i++)
                {
                        for (int j = 0; j < NUM_SHAPE; j++)
                        {
                                Card cards(a[j], b[i]);
                                deck.push_back(cards);
                        }
                }
                

                //!!!!!!!
                // now we need to shuffle the deck
                srand(time(0)); // to get random numbers each run
                random_shuffle(deck.begin(), deck.end());
                
                // ***
                // Each of the players receives 26 cards
                int i = 0;
                while (!deck.empty())
                {
                        p1.add_to_stack(deck.at(i));
                        // p1._stack().push_back(deck.at(i));
                        i++;
                        p2.add_to_stack(deck.at(i));
                        // p2._stack().push_back(deck.at(i));
                        i++;
                }
                
                // now we redy to play
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
        }
        void Game::printWiner()
        {
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


        }

}