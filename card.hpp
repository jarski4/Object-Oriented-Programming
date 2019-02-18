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
     Card(Suit s, Rank r)
     : bits((unsigned)s << 4 | (unsigned)r) {} //c-style casts being used
     /*
     Card(s, r){
        Rank rank = r;
        Suit suit = s;
     }; //constructor
     */
     void print(Card a) const{};
     /* enum get_rank(Card a) const{ return a.rank;} */
     enum get_rank() const{ return (Rank)(0b001111 & bits);}; //0xf & bits
     enum get_suit() const{ return (Suit)((0b110000 & bits) >> 4);};

     bool operator==(Card c) const{
       return bits == c.bits;
     }

   private:
  /*  Rank rank;
    Suit suit;
    */
    unsigned char bits;
};

/*
struct Card{
  int id;

  Card(int id);
};
*/
//The ":" means the struct is inheriting the members of Card
struct StandardCard : Card{
  public:
    StandardCard(int n, Suit s, Rank r) : Card(n), Suit(s), Rank(r) {}

    Suit suit;
    Rank rank;
};

struct JokerCard : Card{
  public:
    JokerCard(int n, Color c) : Card(n), Color(c) {}

    Color color;
};
/*
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
*/
bool operator==(Card a, Card b){
  return a.bits==b.bits;
}
bool operator!=(Card a, Card b){
  return !(a.bits==b.bits);
}
bool operator>(Card a, Card b){
  return a.bits > b.bits;
}
bool operator<(Card a, Card b){
  return a.bits < b.bits;
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
