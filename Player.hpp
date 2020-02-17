#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "DeckBuilder.hpp"
#include <vector>

class Player{
  private:
    DeckBuilder deck;
    std::vector<GreenCard *> hand;
    std::vector<Holding> holdings;
    std::vector<Personality> activePersonalities;
    int numberOfProvinces;
    //oi eparxies einai mayres kartes
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
      void GetGreenCard();
};

#endif
