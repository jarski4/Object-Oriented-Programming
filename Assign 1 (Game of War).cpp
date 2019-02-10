/*
   COPYRIGHT (C) 2019 Jared Skinner (jss136) All rights reserved.
   Object Oriented Programming
   Author.  Jared Skinner
            jss136@zips.uakron.edu
   Version. 1.01 02.03.2019

  Implement the card game of War.
  Emphasize clean, crisp abstractions.
  Provide README file that describes elements of the game.
*/
#include "card.hpp"
#include "game.hpp"

#include <iostream>
#include <deque>


/* Thinking through the problem:
2 players (played with 52 unique cards)
   each begin with randomly selected cards - no repeats of a card

What's a card? - an object consisting of suit and rank
   4 suits, 13 ranks

The players hand can be represented with a stack???
   the player is always pulling the top card off their deck
   however... they put acquired cards at bottom of deck
   or... the new cards are set aside in pile then when original deck runs out
   the new pile is shuffled and used as if it were original

Cards' values are compared and the player w/ the higher value takes both cards

repeat previous steps until a player acquires ALL cards - program ends

EXTRA - allow the user to choose which newly acquired cards are put in deck first (actually making it a game)
*/

int main(){
  std::cout << "Welcome To the Game of War\n";

  Deck deck = new_deck(); //Will create the 52 cards to be played with
  Player p1;
  Player p2;
  setup_game(deck, p1, p2);
  play_game(p1, p2);

  return 0;
}
