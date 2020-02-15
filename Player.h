#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DeckBuilder.hpp"

class Player{
  private:
    DeckBuilder* deck;
//  GreenCard* fateDeck;
    GreenCard* hand;
//  BlackCard* dynastyDeck;
    int numberOfProvinces;
    //oi eparxies einai mayres kartes
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
};

#endif
