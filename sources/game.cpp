#include "game.hpp"
#include "card.hpp"
#include <vector>
const int NUM_SHAPE = 4;
const int NUM_OF_NUMCARD = 13; 

namespace ariel
{
        Game::Game(Player &p1, Player &p2) : _p1(p1), _p2(p2)
        {
                // first we need to creat the deck cards for the game

                // we creat 52 cards
                vector<Card> deck(52);
                string a[NUM_SHAPE] = {"Spades", "Hearts", "Clubs", " Diamonds"};
                int b[NUM_OF_NUMCARD] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
                for (int i = 0; i < NUM_SHAPE; i++)
                {
                        for (int j = 0; j < NUM_OF_NUMCARD; j++)
                        {
                                Card cards(b[j], a[i]);
                                deck.push_back(cards);
                        }
                }

                // now we need to shuffle the deck 


                

                
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