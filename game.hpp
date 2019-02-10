#IF

##include "card.hpp"

#include <iostream>
#include <algorithm> // std::shuffle
#include <random>
#include <ctime>
#include <deque>

//using deque as the structure to hold all the cards
struct Deck : std::deque<Card> {
  using std::deque<Card>::deque;
};

//May need to add member functions later. Don't know what for, but still...
struct Player{
  Deck deck;

  size(){ //retruns the number of elements in a players deck
    return deck.empty();
  }

};
//check to see if either player has an empty deck, indicating the game has ended
bool end_game(Player a, Player b){
    return (a.empty() || b.empty()); //MAY NEED TO CHANGE
}

Deck new_deck(){

  Deck d{
      Card(Spade, ace);
      Card(Spade, two);
      Card(Spade, three);
      Card(Spade, four);
      Card(Spade, five);
      Card(Spade, six);
      Card(Spade, seven);
      Card(Spade, eight);
      Card(Spade, nine);
      Card(Spade, ten);
      Card(Spade, jack);
      Card(Spade, queen);
      Card(Spade, king);

      Card(Heart, ace);
      Card(Heart, two);
      Card(Heart, three);
      Card(Heart, four);
      Card(Heart, five);
      Card(Heart, six);
      Card(Heart, seven);
      Card(Heart, eight);
      Card(Heart, nine);
      Card(Heart, ten);
      Card(Heart, jack);
      Card(Heart, queen);
      Card(Heart, king);

      Card(Diamond, ace);
      Card(Diamond, two);
      Card(Diamond, three);
      Card(Diamond, four);
      Card(Diamond, five);
      Card(Diamond, six);
      Card(Diamond, seven);
      Card(Diamond, eight);
      Card(Diamond, nine);
      Card(Diamond, ten);
      Card(Diamond, jack);
      Card(Diamond, queen);
      Card(Diamond, king);

      Card(Club, ace);
      Card(Club, two);
      Card(Club, three);
      Card(Club, four);
      Card(Club, five);
      Card(Club, six);
      Card(Club, seven);
      Card(Club, eight);
      Card(Club, nine);
      Card(Club, ten);
      Card(Club, jack);
      Card(Club, queen);
      Card(Club, king);

      return d;
}


void setup_game(Deck d, Player p1, Player p2){
  //shuffle the new deck before dealing out to each player
  std::random_device rng;
  std::minstd_rand prng(rng()) //random number generator; easy to use, quick to type
  std::shuffle(d.begin(), d.end(), prng);

  do{
    Card std::hold_place = d.begin();
    std::push_front(hold_place, p2.deck);
    d.pop_front();

    hold_place = d.begin();
    std::push_front(hold_place, p1.deck);
    d.pop_front();

  }while(!d.empty());
  //The empty deck/deque is still in memory; need to delete somehow??????
}

void tie_game(Player p1, Player p2){
//in case of ties, each player places 3 more cards and the last cards are compared

}


void play_game(Player p1, Player p2){
  //two players have been created; the game begins...
  //each player takes the top card off their deck (begin of each deque)
  do{
    //the winning player takes both Cards
    //The winner takes both cards (loser's card is swapped to the back, then pop_backed, then push_backed into other players deque)
    if(p1.deck.begin() == p2.deck.begin())
      tie_game(p1, p2);
    else if(p1.deck.begin() > p2.deck.begin()){
      //player 1 gets both cards added to "bottom" of his deck
      Card holder = p1.deck.begin();
      pop_front(p1.deck);
      push_back(p1.deck, holder);

      holder = p2.deck.begin();
      pop_front(p2.deck);
      push_back(p1.deck, holder);
    }
    else if(p1.deck.begin() < p2.deck.begin()){
      //player 2 gets both cards added to "bottom"" of his deck
      Card holder = p2.deck.begin();
      pop_front(p2.deck);
      push_back(p2.deck, holder);

      holder = p1.deck.begin();
      pop_front(p1.deck);
      push_back(p2.deck, holder);
    }
  }while(!end_game(p1, p2));

  //Declare the winner of the game ; a player wins by having collected all the cards
  if(p1.deck.size() == 52)
    std::cout << "Player 2 is the winner!\n";
  else
    std::cout << "Player 2 is the winner!\n";

  return;
}

#END_IF
