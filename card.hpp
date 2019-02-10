#PRAGMA ONCE

enum Suit(){
  Heart,
  Diamond,
  Club,
  Spade;
};

enum Rank(){
   ace,
   two,
   three,
   four,
   five,
   six,
   seven,
   eight,
   nine,
   ten,
   jack,
   queen,
   king;
};

//class that combines the suit and rank
class Card(){
   public:
     Card(s, r){
        Rank rank = r;
        Suit suit = s;
     }; //constructor
     void print(Card a) const{};
     enum get_rank(Card a) const{ return a.Rank;};
     enum get_suit(Card a) const{ return a.Suit;};
   private:
    Rank rank;
    Suit suit;
};
//overlaoded operators to compare value of cards while game is played
bool operator==(Card a, Card b){
  return (a.Rank == b.Rank);
}
bool operator>(Card a, Card b){
  return a.Rank>b.Rank;
}
bool operator<(Card a, Card b){
  return a.Rank<b.Rank;
}


//Error handling
Rank (int r) : rep(r){
  if (r < 0 || r > 13)
  throw std::logic_error("invalid rank");
}
Suit (int s) : rep(s){
   if (s < 0 || s > 3)
   throw std::logic_error("invlaid  suit");
}
