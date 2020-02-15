#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "DeckBuilder.hpp"
#include <vector>
#include <list>

class Player{
  private:
    DeckBuilder* deck;
    vector<GreenCard> hand;
    vector<Holding> holdings;
    vector<Personality> activePersonalities;
    int numberOfProvinces;
    //oi eparxies einai mayres kartes
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
};

#endif